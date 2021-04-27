#include "ECS.h"


RenderServer* Component::get_render_server() {
	return get_object()->get_manager()->get_render_server(); 
}

TextureServer* Component::get_texture_server(){
	return get_object()->get_manager()->get_texture_server();
}
