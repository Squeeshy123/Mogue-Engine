#include "TestLevel.h"
#include "../Core/RenderComponent.h"
#include <memory>

TestLevel::TestLevel() {
	//objects.assign(1, Object(std::vector<Component>(5, RenderComponent())));
	objects.push_back(Object());
}

void TestLevel::add_object() {
	objects.push_back(Object(std::vector<std::unique_ptr<Component>>(1, new RenderComponent())));
}

void TestLevel::begin()
{
	Level::begin();
}

void TestLevel::tick(float deltaTime)
{
	Level::tick(deltaTime);
}
