#include "ECS.h"

std::shared_ptr<Object> Level::add_object()
{
	std::shared_ptr<Object> o = std::make_shared<Object>();
	objects.push_back(o);
	return o;
}

template<class ComponentType, typename ...Args>
inline std::shared_ptr<ComponentType> Object::add_component(Args&&... p_args)
{
	std::shared_ptr<ComponentType> c = std::make_shared<ComponentType>(std::forward(p_args));
	// Set Owner here
	return c;
}