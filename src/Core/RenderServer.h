#pragma once

#include "Core/TextureAsset.h"

#include <SDL/SDL.h>
#include <stdio.h>
#include <vector>


class RenderServer
{
	public:
		SDL_Renderer* renderer;
		RenderServer(SDL_Window* window, int index, uint32_t flags);
		~RenderServer();
		void DrawRectangle(int x, int y, int w, int h);

		void Begin();
		void Tick();
		void End_Tick();

		void add_texture_to_buffer(TextureAsset* surface);
};
