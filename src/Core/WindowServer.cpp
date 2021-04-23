#include "Core/WindowServer.h"
#include <stdio.h>


WindowServer::WindowServer(const char* name, int window_pos_x, int window_pos_y, int width, int height, uint32_t flags)
{
	window = SDL_CreateWindow(name, window_pos_x, window_pos_y, width, height, flags);
	printf("Created window....\n");
}

WindowServer::~WindowServer()
{
	SDL_DestroyWindow(window);
}

void WindowServer::Begin()
{
	if (!window)
	{
		printf("Failed to create window\n %s", SDL_GetError());
	}
}

void WindowServer::Tick()
{
	SDL_UpdateWindowSurface(window);
}

void WindowServer::Input(SDL_Event e)
{
	
}
