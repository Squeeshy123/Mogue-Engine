#pragma once
#include "Core/RenderAsset.h"
#include "Core/TextureManager.h"

#include <SDL/SDL.h>


class TextureAsset :
    public RenderAsset
{
    public:
        TextureAsset(TextureManager* mtexture_manager, std::string path);
        SDL_Texture* get_texture();
        SDL_Rect* get_dimensions();
};

