#include <SDL/SDL.h>
#include <vector>

#include "Core/WindowManager.h"
#include "Core/RenderManager.h"
#include "Core/UIManager.h"
#include "Core/TextureManager.h"

#include "Libs/imgui.h"
#include "Libs/imgui_sdl.h"


#include "Core/Level.h"
#include "Test/TestLevel.h"



int main(int argc, char* argv[]) {

	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("Failed to initialize SDL!!\n");
	}
	WindowManager* window_manager = new WindowManager("Mogue", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
	window_manager->Begin();

	RenderManager* render_manager = new RenderManager(window_manager->window, -1, SDL_RENDERER_ACCELERATED);
	render_manager->Begin();

	UIManager* ui_manager = new UIManager(render_manager->renderer, 800, 800);
	
	TextureManager* texture_manager = new TextureManager(render_manager);
	

	TestLevel currentLevel = TestLevel();

	//render_manager->add_texture_to_buffer(texture_manager->create_texture_asset("icon.png"));
	
	bool run = true;
	while (run)
	{
		

		int wheel = 0;
		currentLevel.tick(0.1f);
		SDL_Event e;

		window_manager->Tick();
		render_manager->Tick();
		ui_manager->tick();

		while (SDL_PollEvent(&e))
		{
			window_manager->Input(e);

			if (e.type == SDL_QUIT) run = false;
			if (e.type == SDL_WINDOWEVENT)
			{
				if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
				{
					ui_manager->getIO().DisplaySize.x = static_cast<float>(e.window.data1);
					ui_manager->getIO().DisplaySize.y = static_cast<float>(e.window.data2);
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
		ui_manager->getIO().DeltaTime = 1.0f / 60.0f;
		ui_manager->getIO().MousePos = ImVec2(static_cast<float>(mouseX), static_cast<float>(mouseY));
		ui_manager->getIO().MouseDown[0] = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);
		ui_manager->getIO().MouseDown[1] = buttons & SDL_BUTTON(SDL_BUTTON_RIGHT);
		ui_manager->getIO().MouseWheel = static_cast<float>(wheel);
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
		

		render_manager->End_Tick();
	}

	

	delete render_manager;
	delete ui_manager;
	delete window_manager;
	

	return 0;
}