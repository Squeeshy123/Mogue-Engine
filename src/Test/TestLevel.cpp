#include "TestLevel.h"
#include <memory>

TestLevel::TestLevel() {
}

void TestLevel::begin()
{
	Level::begin();
}

void TestLevel::tick(float deltaTime)
{
	Level::tick(deltaTime);
}
