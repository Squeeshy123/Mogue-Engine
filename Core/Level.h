#pragma once
#include "ECS.h"

#include <vector>
#include <SDL/SDL.h>
class Level
{
	public:
		Manager* manager;

		Level();

		virtual void begin();
		virtual void tick(float deltaTime);
};

