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
class Manager;

using ComponentID = std::size_t;

inline ComponentID getComponentID() {
	static ComponentID lastID = 0;
	return lastID++;
}

template<typename T> inline ComponentID getComponentTypeID() noexcept {
	static ComponentID typeID = getComponentID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component {
	private: 
		Object* object = nullptr;

	public:
		bool enabled = true;


		virtual ~Component() {}

		virtual void begin() {}
		virtual void tick(float deltaTime)  {}
		
		void set_object(Object* obj) { object = obj; }
		Object* get_object(){ return object; };

		RenderServer* get_render_server(); 
		TextureServer* get_texture_server();
};

class Object {
	private:
		Manager* manager = nullptr;
		
		bool enabled = true;
		
		std::vector<Component*> components;

		ComponentArray componentArray;
		ComponentBitSet componentBitSet;

	public:

		

		~Object(){
			
		}
		void begin() {
			for (auto& c : components) c->begin();
		}
		void tick(float deltaTime) {
			for (auto& c : components) c->tick(deltaTime);
		}

		bool isEnabled() { return enabled; }
		void destroy() { enabled = false; }

		Manager* get_manager(){ return manager; }
		void set_manager(Manager* m) { manager = m; };

		template <typename T> bool hasComponent() const {
			return componentBitSet[getComponentID()];
		}
		
		template <typename T, typename... TArgs>
		T& addComponent(TArgs&&... mArgs) {
			T* c(new T(std::forward<TArgs>(mArgs)...));
			c->set_object(this);
			components.emplace_back(c);

			componentArray[getComponentTypeID<T>()] = c;
			componentBitSet[getComponentTypeID<T>()] = true;

			c->begin();
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

		RenderServer* render_server = nullptr;
		TextureServer* texture_server = nullptr;

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

		void begin() {
			for (auto& o : objects) o->begin();
		}

		void tick(float deltaTime) {
			for (auto& o : objects) o->tick(deltaTime);
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
			o->set_manager(this);
			objects.emplace_back(std::move(uPtr));
			return *o;
		}


};




