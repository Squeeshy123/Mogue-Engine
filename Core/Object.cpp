#include "Object.h"
#include "RenderComponent.h"
std::vector<Component*> components;

Object::Object(std::vector<Component*> comps)
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
