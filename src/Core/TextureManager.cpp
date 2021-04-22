#include "Core/TextureManager.h"

RenderManager* gRenderer;

TextureManager::TextureManager(RenderManager* renderer)
{
    gRenderer = renderer;
}

SDL_Texture* TextureManager::load_texture(std::string path)
{
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(gRenderer->renderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}


// Creates a texture asset to be loaded to the render manager
TextureAsset* TextureManager::create_texture_asset(std::string path) {
    return new TextureAsset(this, path);
}