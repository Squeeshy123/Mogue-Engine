#include "ECS.hpp"

#include "Components.h"

	template <class TComponent, typename... Args>
	void add_component(Args&&... params) {
		debug();
		components.emplace_back(std::make_unique< TComponent >(std::forward< Args >(params)...));
		debug();
	}


	template<class ComponentType>
	ComponentType& Object::GetComponent() {
		for (auto&& component : components) {
			if (component->get_id() == ComponentType::get_id())
				return *static_cast<ComponentType*>(component.get());
		}
		return *std::unique_ptr< ComponentType >(nullptr);
	}


	Object* Component::get_object() { return Component::owner; }

	void Component::set_object(Object* obj) { Component::owner = obj; }

RenderServer* Component::get_render_server() {
	return get_object()->get_manager()->get_render_server(); 
}

Component::Component(Object* p_owner)
{
	owner = p_owner;
}

TextureServer* Component::get_texture_server(){
	return get_object()->get_manager()->get_texture_server();
}

