#pragma once

#include "AssetTypes/TextureAsset.h"

#include <SDL/SDL.h>
#include <stdio.h>
#include <vector>


class RenderManager
{
	public:
		SDL_Renderer* renderer;
		RenderManager(SDL_Window* window, int index, uint32_t flags);
		~RenderManager();
		void DrawRectangle(int x, int y, int w, int h);

		void Begin();
		void Tick();
		void End_Tick();

		void add_texture_to_buffer(TextureAsset* surface);
};

