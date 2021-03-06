#include "Libs/imgui.h"
#include "ECS.h"



namespace Mogue {

	//Component
	init_component_cpp(Component, 0, "Component");
	
	void Component::list_default_properties(std::string display_name){
		if(ImGui::CollapsingHeader(display_name.c_str())) 
		{
			ImGui::Checkbox("Is Enabled", &is_enabled);
		}
	}

	void Component::list_properties(){
		list_default_properties("Component");
	}

	// Object

	void Object::begin() {
		for(auto& c : components) {
			if (c->get_enabled()) 
				c->begin();
			}
		for(auto& o : children) {
			if (o->get_enabled()) 
				o->begin();
			}
	}

	void Object::tick(float deltaTime) {
		for(auto& c : components) {
			if (c->get_enabled()) {
				c->tick(deltaTime);
			}
		}
		for(auto& o : children) {
			if (o->get_enabled()) 
				o->tick(deltaTime);
		}
	}

	void Object::input(InputEvent event) {
		for(auto& c : components) {
			if (c->get_enabled())
				c->input(event);
		}
		for(auto& o : children) {
			if (o->get_enabled()) 
				o->input(event);
		}
	}

	void Object::end_tick() {
		for(auto& c : components){
			if (c->get_enabled())
				c->end_tick();
		}
		for(auto& o : children) {
			if (o->get_enabled()) 
				o->end_tick();
		}
	}

	void Object::end(){
		for(auto& c : components){
			if (c->get_enabled())
				c->end();
		}
		for(auto& o : children) {
			if (o->get_enabled()) 
				o->end();
		}
	}


	std::shared_ptr<Object> Object::create_child() {
		std::shared_ptr<Object> o = std::make_shared<Object>();
		o->set_enabled(true);
		o->set_name("Object" + std::to_string(children.size()));
		children.push_back(o);
		return o;
	}

	// Scene
	std::shared_ptr<Object> Scene::add_object() {
		std::shared_ptr<Object> o = std::make_shared<Object>();
		o->set_enabled(true);
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
		//printf("scene ticking");
		for(auto& o : objects){
			printf("Ticking object");
			
			o->tick(deltaTime);
				
			
		}
	}
	void Scene::begin() {
		for(auto& o : objects){
			if (o->get_enabled())
				o->begin();
		}
	}
	void Scene::input(InputEvent event){
		for(auto& o : objects){
			if (o->get_enabled())
				o->input(event);
		}
	}
	void Scene::end_tick(){
		for(auto& o : objects){
			if (o->get_enabled())
				o->end_tick();
		}
	}
	void Scene::end(){
		for(auto& o : objects){
			if (o->get_enabled())
				o->end();
		}
	}
}