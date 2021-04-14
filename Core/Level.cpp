#include "Level.h"


Level::Level()
{
}

Level::Level(std::vector<Object> objs) {
	objects = objs;
}

void Level::begin()
{
	for (int i = 0; i < objects.size(); i++) {
		objects[i].begin();
	}
}

void Level::tick(float deltaTime)
{
	for (int i = 0; i < objects.size(); i++) {
		objects[i].tick(deltaTime);
	}
}
