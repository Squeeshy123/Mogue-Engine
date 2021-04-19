#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

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

		virtual void init() {}
		virtual void update() {}
		virtual void draw() {}
		virtual ~Component(){}

};

class Object {
	private:
		bool enabled = true;

		std::vector<std::unique_ptr<Component>> components;

		ComponentArray componentArray;
		ComponentBitSet componentBitSet;

	public:
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
	public:
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

		Object& addObject() {
			Object* o = new Object();
			std::unique_ptr<Object> uPtr{ o };
			objects.emplace_back(std::move(uPtr));
			return *o;
		}
};