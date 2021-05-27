#pragma once
#include <SDL/SDL.h>

class WindowServer
{
	public:
		SDL_Window* window = nullptr;
		WindowServer(const char* Name, int window_pos_x, int window_pos_y, int width, int height,  uint32_t flags);
		~WindowServer();
		
		void begin();
		void tick();
		void input(SDL_Event e);
};

