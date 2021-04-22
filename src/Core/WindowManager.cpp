#include "Core/WindowManager.h"
#include <stdio.h>


WindowManager::WindowManager(const char* name, int window_pos_x, int window_pos_y, int width, int height, uint32_t flags)
{
	window = SDL_CreateWindow(name, window_pos_x, window_pos_y, width, height, flags);
	printf("Created window....\n");
}

WindowManager::~WindowManager()
{
	SDL_DestroyWindow(window);
}

void WindowManager::Begin()
{
	if (!window)
	{
		printf("Failed to create window\n %s", SDL_GetError());
	}
}

void WindowManager::Tick()
{
	SDL_UpdateWindowSurface(window);
}

void WindowManager::Input(SDL_Event e)
{
	
}
