#include "ECS.h"

namespace Mogue {

	//Component



	// Object
	template<class ComponentType, typename ...Args>
	inline std::shared_ptr<ComponentType> Object::add_component(Args&&... p_args) {
		std::shared_ptr<ComponentType> c = std::make_shared<ComponentType>(std::forward(p_args));
		c->set_owner(std::make_shared(this));
		return c;
	}


	void Object::begin() {
		for(auto& c : components) 
			if (c->is_enabled) 
				c->begin();
	}

	void Object::tick(float deltaTime) {
		for(auto& c : components) 
			if (c->is_enabled) 
				c->tick(deltaTime);
	}

	void Object::input(InputEvent event) {
		for(auto& c : components) 
			if (c->is_enabled) 
				c->input(event);
	}

	void Object::end_tick() {
		for(auto& c : components)
			if (c->is_enabled)
				c->end_tick();
	}

	void Object::end(){
		for(auto& c : components)
			if (c->is_enabled)
				c->end();
	}


	// Scene
	std::shared_ptr<Object> Scene::add_object() {
		std::shared_ptr<Object> o = std::make_shared<Object>();
		o->is_enabled = true;
		o->set_name("Object" + std::to_string(objects.size()));
		objects.push_back(o);
		return o;
	}

	std::shared_ptr<Object> Scene::get_object(int index) {
		if(index < objects.size()) {
			return objects[index];
		}
		else {
			Error("Object Index out of range!");
		}
	}

	void Scene::tick(float deltaTime) {
		for(auto& o : objects)
			if (o->is_enabled)
				o->tick(deltaTime);
	}
	void Scene::begin() {
		for(auto& o : objects)
			if (o->is_enabled)
				o->begin();
	}
	void Scene::input(InputEvent event){
		for(auto& o : objects)
			if (o->is_enabled)
				o->input(event);
	}
	void Scene::end_tick(){
		for(auto& o : objects)
			if (o->is_enabled)
				o->end_tick();
	}
	void Scene::end(){
		for(auto& o : objects)
			if (o->is_enabled)
				o->end();
	}
}