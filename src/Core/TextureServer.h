#pragma once


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>

class TextureAsset;
class RenderServer;

class TextureServer
{
	public:
		TextureServer(RenderServer* renderer);

		TextureAsset* create_texture_asset(std::string path);
		SDL_Texture*  load_texture(std::string path);
};

#include "RenderServer.h"