#include "Object.h"
#include "RenderComponent.h"
#include <memory>
std::vector<std::unique_ptr<Component>> components;

Object::Object(std::vector<std::unique_ptr<Component>> comps)
{
}

void Object::begin()
{
	for (int i = 0; i < components.size(); i++) {
		components[i]->begin();
	}
}

void Object::tick(float deltaTime)
{
	for (int i = 0; i < components.size(); i++) {
		components[i]->tick(deltaTime);
	}
}
