#pragma once

#include "Libs/imgui.h"
#include "Libs/imgui_sdl.h"

class UIManager
{
	private:
		
	public:

		UIManager(SDL_Renderer* renderer, int size_x, int size_y);
		~UIManager();

		void tick();

		ImGuiIO& getIO();

};

