#include "Core/TextureAsset.h"

TextureServer* texture_manager;

SDL_Texture* texture;
SDL_Rect tex_size;


TextureAsset::TextureAsset(TextureServer* mtexture_manager, std::string path)
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

void TextureAsset::set_dimensions(int x, int y, int w, int h)
{
	tex_size.x = x;
	tex_size.y = x;
	tex_size.w = w;
	tex_size.h = h;
}
