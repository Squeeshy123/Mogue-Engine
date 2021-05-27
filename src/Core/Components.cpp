#include "Components.h"

SpriteComponent::SpriteComponent(std::string p_path) : Component() {
	sprite_path = p_path;
	t_asset = get_texture_server()->create_texture_asset(sprite_path);
	get_render_server()->add_texture_to_buffer(t_asset);
}

void SpriteComponent::begin() {
	
}