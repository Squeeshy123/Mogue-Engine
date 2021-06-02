#include "ECS.h"

//Component
void Mogue::Component::set_owner(std::shared_ptr<Object> obj) {
	owner = obj;
}
std::shared_ptr<Object> Mogue::Component::get_owner() {
	return owner;
}

// Object
template<class ComponentType, typename ...Args>
inline std::shared_ptr<ComponentType> Mogue::Object::add_component(Args&&... p_args) {
	std::shared_ptr<ComponentType> c = std::make_shared<ComponentType>(std::forward(p_args));
	c->set_owner(std::make_shared(this));
	return c;
}


void Mogue::Object::begin() {
	for(auto& c : components) 
		if (c->is_enabled) 
			c->begin();
}

void Mogue::Object::tick(float deltaTime) {
	for(auto& c : components) 
		if (c->is_enabled) 
			c->tick(deltaTime);
}

void Mogue::Object::input(InputEvent event) {
	for(auto& c : components) 
		if (c->is_enabled) 
			c->input(event);
}

void Mogue::Object::end_tick() {
	for(auto& c : components)
		if (c->is_enabled)
			c->end_tick();
}

void Mogue::Object::end(){
	for(auto& c : components)
		if (c->is_enabled)
			c->end();
}


// Level
std::shared_ptr<Object> Mogue::Level::add_object() {
	std::shared_ptr<Object> o = std::make_shared<Object>();
	objects.push_back(o);
	return o;
}

std::shared_ptr<Object> Mogue::Level::get_object(int index) {
	if(index < objects.size()) {
		return objects[index];
	}
	else {
		Mogue::Error("Object Index out of range!");
	}
}

void Mogue::Level::tick(float deltaTime) {
	for(auto& o : objects)
		if (o->is_enabled)
			o->tick(deltaTime);
}
void Mogue::Level::begin() {
	for(auto& o : objects)
		if (o->is_enabled)
			o->begin();
}
void Mogue::Level::input(InputEvent event){
	for(auto& o : objects)
		if (o->is_enabled)
			o->input(event);
}
void Mogue::Level::end_tick(){
	for(auto& o : objects)
		if (o->is_enabled)
			o->end_tick();
}
void Mogue::Level::end(){
	for(auto& o : objects)
		if (o->is_enabled)
			o->end();
}