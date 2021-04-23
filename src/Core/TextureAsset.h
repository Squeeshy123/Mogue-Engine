#pragma once
#include "Core/RenderAsset.h"
#include "Core/TextureServer.h"

#include <SDL/SDL.h>


class TextureAsset :
    public RenderAsset
{
    public:
        TextureAsset(TextureServer* mtexture_manager, std::string path);
        SDL_Texture* get_texture();
        SDL_Rect* get_dimensions();
        
        void set_dimensions(int x, int y, int w, int h);
};

