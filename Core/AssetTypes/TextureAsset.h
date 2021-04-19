#pragma once
#include "RenderAsset.h"
#include "../TextureManager.h"

#include <SDL/SDL.h>


class TextureAsset :
    public RenderAsset
{
    public:
        TextureAsset(TextureManager* mtexture_manager, std::string path);
        SDL_Texture* get_texture();
        SDL_Rect* get_dimensions();
};

