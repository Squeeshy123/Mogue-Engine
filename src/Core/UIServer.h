#pragma once

#include "Libs/imgui.h"
#include "Libs/imgui_sdl.h"

class UIServer
{
	private:
		
	public:

		UIServer(SDL_Renderer* renderer, int size_x, int size_y);
		~UIServer();

		void tick();

		ImGuiIO& getIO();

};

