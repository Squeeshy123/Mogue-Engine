#include "Core/TextureAsset.h"

TextureManager* texture_manager;

SDL_Texture* texture;
SDL_Rect tex_size;


TextureAsset::TextureAsset(TextureManager* mtexture_manager, std::string path)
{
	// initializes the texture manager
	texture_manager = mtexture_manager;
	int w, h;

	// loads texture from the texture manager and sets the texture so it is accessible
	SDL_Texture* t = texture_manager->load_texture(path);

	// Gets the texture size
	SDL_QueryTexture(t, NULL, NULL, &w, &h);
	
	tex_size.w = w;
	tex_size.h = h;
}

// returns the current texture assets texture
SDL_Texture* TextureAsset::get_texture()
{
	return texture;
}

// returns the size of the texture
SDL_Rect* TextureAsset::get_dimensions()
{
	return &tex_size;
}
