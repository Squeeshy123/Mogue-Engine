#include "TestLevel.h"
#include <memory>

TestLevel::TestLevel() {
	add_object();
}


void TestLevel::add_object() {
	
}

void TestLevel::begin()
{
	Level::begin();
}

void TestLevel::tick(float deltaTime)
{
	Level::tick(deltaTime);
}
