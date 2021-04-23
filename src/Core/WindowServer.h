#pragma once
#include <string>
#include <SDL/SDL.h>
class WindowServer
{
	public:
		SDL_Window* window = nullptr;
		WindowServer(const char* Name, int window_pos_x, int window_pos_y, int width, int height,  uint32_t flags);
		~WindowServer();
		
		void Begin();
		void Tick();
		void Input(SDL_Event e);
};

