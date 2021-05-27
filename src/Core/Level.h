#pragma once
#include "Core/ECS.hpp"

#include <vector>
#include <SDL/SDL.h>

#include "Core/RenderServer.h"


class Level
{
	public:
		Manager* manager = nullptr;
		
		Level();
		Level(RenderServer* render_server, TextureServer* texture_server);

		Object* add_object();

		virtual void begin();
		virtual void tick(float deltaTime);
};

