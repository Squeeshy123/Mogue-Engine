#include "TestLevel.h"
#include "../Core/RenderComponent.h"

TestLevel::TestLevel() {
	//objects.assign(1, Object(std::vector<Component>(5, RenderComponent())));
	objects.push_back(Object(std::vector<Component>(1, RenderComponent())));
}

void TestLevel::begin()
{
	Level::begin();
}

void TestLevel::tick(float deltaTime)
{
	Level::tick(deltaTime);
}
