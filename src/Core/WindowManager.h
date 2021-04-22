#pragma once
#include <string>
#include <SDL/SDL.h>
class WindowManager
{
	public:
		SDL_Window* window = nullptr;
		WindowManager(const char* Name, int window_pos_x, int window_pos_y, int width, int height,  uint32_t flags);
		~WindowManager();
		
		void Begin();
		void Tick();
		void Input(SDL_Event e);
};

