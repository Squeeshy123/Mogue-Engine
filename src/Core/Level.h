#pragma once
#include "Core/ECS.h"

#include <vector>
#include <SDL/SDL.h>

#include "Core/RenderServer.h"


class Level
{
	public:
		Manager* manager;
		Level();
		Level(RenderServer render_manager, TextureServer texture_manager);

		virtual void begin();
		virtual void tick(float deltaTime);
};

