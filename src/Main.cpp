#include <SDL/SDL.h>
#include <vector>

#include "Core/WindowServer.h"
#include "Core/RenderServer.h"
#include "Core/UIServer.h"
#include "Core/TextureServer.h"

#include "Libs/imgui.h"
#include "Libs/imgui_sdl.h"


#include "Core/Level.h"
#include "Test/TestLevel.h"



int wmain(int argc, char* argv[]) {

	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("Failed to initialize SDL!!\n");
	}
	if (!(IMG_Init(IMG_INIT_PNG)))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
	
	WindowServer* window_manager = new WindowServer("Mogue", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
	window_manager->Begin();

	RenderServer* render_server = new RenderServer(window_manager->window, -1, SDL_RENDERER_ACCELERATED);
	render_server->Begin();

	UIServer* ui_server = new UIServer(render_server->renderer, 800, 800);
	
	TextureServer* texture_server = new TextureServer(render_server);
	
	

	TestLevel currentLevel = TestLevel();

	TextureAsset* ta = texture_server->create_texture_asset("C:\\Users\\finnm\\Desktop\\CSCWork\\MogueEngine\\Mogue\\icon.png");

	ta->set_dimensions(100, 100, 100, 100);

	render_server->add_texture_to_buffer(ta);
	
	bool run = true;
	while (run)
	{
		

		int wheel = 0;
		currentLevel.tick(0.1f);
		SDL_Event e;

		window_manager->Tick();
		render_server->Tick();
		ui_server->tick();

		while (SDL_PollEvent(&e))
		{
			window_manager->Input(e);

			if (e.type == SDL_QUIT) run = false;
			if (e.type == SDL_WINDOWEVENT)
			{
				if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
				{
					ui_server->getIO().DisplaySize.x = static_cast<float>(e.window.data1);
					ui_server->getIO().DisplaySize.y = static_cast<float>(e.window.data2);
				}
			}
			else if (e.type == SDL_MOUSEWHEEL)
			{
				wheel = e.wheel.y;
			}
		}

		int mouseX, mouseY;
		const int buttons = SDL_GetMouseState(&mouseX, &mouseY);

		// Mouse Re-centering
		ui_server->getIO().DeltaTime = 1.0f / 60.0f;
		ui_server->getIO().MousePos = ImVec2(static_cast<float>(mouseX), static_cast<float>(mouseY));
		ui_server->getIO().MouseDown[0] = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);
		ui_server->getIO().MouseDown[1] = buttons & SDL_BUTTON(SDL_BUTTON_RIGHT);
		ui_server->getIO().MouseWheel = static_cast<float>(wheel);
		
		/*
		ImGui::NewFrame();
		// Imgui Stuff
		ImGui::Begin("Debug");
		if (ImGui::Button("Hello")) {
			currentLevel.add_object();
		}
		ImGui::End();
		
		

		ImGui::Render();
		ImGuiSDL::Render(ImGui::GetDrawData());
		*/
		

		render_server->End_Tick();
	}

	

	delete render_server;
	delete ui_server;
	delete window_manager;
	

	return 0;
}