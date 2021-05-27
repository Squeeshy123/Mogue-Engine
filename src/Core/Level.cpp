#include "Core/Level.h"

Level::Level()
{
	manager = nullptr;
}

Level::Level(RenderServer* render_server, TextureServer* texture_server)
{
	manager = new Manager();
	manager->set_render_server(render_server);
	manager->set_texture_server(texture_server);
}

Object* Level::add_object() {
	return manager->add_object();
}

void Level::begin()
{
	manager->begin();
}

void Level::tick(float deltaTime)
{
	manager->tick(deltaTime);
}
