#pragma once
#include "Object.h"
#include <vector>
class Level
{
	public:
		std::vector<Object*> objects;
		Level();
		Level(std::vector<Object*> objects);
		virtual void begin();
		virtual void tick(float deltaTime);
};

