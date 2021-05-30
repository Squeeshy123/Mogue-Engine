#pragma once
#include <vector>
#include <memory>
#include <GLFW/glfw3.h>

class Component;
class Object;
class Level;


class Component {
	private:
		std::shared_ptr<Object> owner;

	public:
		virtual void tick(float dT);
		virtual void begin();
		virtual void input();
};

class Object {

	std::vector<std::shared_ptr<Component>> components;

	template <class ComponentType, typename... Args>
	std::shared_ptr<ComponentType> add_component(Args&&... args);

};

class Level {
	std::vector<std::shared_ptr<Object>> objects;


	std::shared_ptr<Object> add_object();


};


