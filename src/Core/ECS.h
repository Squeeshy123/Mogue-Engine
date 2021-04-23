#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

#include "Core/RenderServer.h"
#include "Core/TextureServer.h"

class Object;
class Component;

using ComponentID = std::size_t;

inline ComponentID getComponentID() {
	static ComponentID lastID = 0;
	return lastID++;
}

template<typename T> inline ComponentID getComponentTypeID() noexcept {
	static ComponentID typeID = getComponentID();
	return typeID();
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component {
	public:
		Object* object;

		bool enabled = true;

		virtual ~Component(){}

		virtual void init() {}
		virtual void update() {}
		virtual void draw() {}
		
		RenderServer* get_render_manager() {if(!object){ object->get_render_manager(); } };
		TextureServer* get_texture_manager() { if(!object) { object->get_texture_manager(); } };

};

class Object {
	private:
		bool enabled = true;

		std::vector<std::unique_ptr<Component>> components;

		ComponentArray componentArray;
		ComponentBitSet componentBitSet;

	public:

		Manager* manager;

		~Object(){
			
		}

		void update() {
			for (auto& c : components) c->update();
			for (auto& c : components) c->draw();
		}

		void draw() { }
		bool isEnabled() { return enabled; }
		void destroy() { enabled = false; }



		template <typename T> bool hasComponent() const {
			return componentBitSet[getComponentID()];
		}
		
		template <typename T, typename... TArgs>
		T& addComponent(TArgs&&... mArgs) {
			T* c(new T(std::forward<TArgs>(mArgs...)));
			c->object = this;
			std::unique_ptr<Component> uPtr{ c };
			components.emplace_back(std::move(uPtr));

			componentArray[getComponentTypeID<T>()] = c;
			componentBitSet[getComponentTypeID<T>()] = true;

			c->init();
			return *c;
		}

		template<typename T> T& getComponent() const
		{
			auto ptr(componentArray[getComponentTypeID<T>()]);
			return *static_cast<T*>(ptr);
		}
};

class Manager
{
	
	private:
		std::vector<std::unique_ptr<Object>> objects;

		RenderServer* render_server;
		TextureServer* texture_server;

	public:


		void set_render_server(RenderServer* server) {
			render_server = server;
		}
		void set_texture_server(TextureServer* server){
			texture_server = server;
		}

		RenderServer* get_render_server(){
			return render_server;
		}

		TextureServer* get_texture_server(){
			return texture_server;
		}

		void update() {
			for (auto& o : objects) o->update();
		}
		void draw() {
			for (auto& o : objects) {
				for (auto& o : objects) {
					o->draw();
				}
			}
		}
		void refresh(){
			objects.erase(std::remove_if(std::begin(objects), std::end(objects), 
				[](const std::unique_ptr<Object>& mObject)
				{
					return !mObject->isEnabled();
				}),
				std::end(objects));
		}

		Object& add_object() {
			Object* o = new Object();
			std::unique_ptr<Object> uPtr{ o };
			o->manager = this;
			objects.emplace_back(std::move(uPtr));
			return *o;
		}


};