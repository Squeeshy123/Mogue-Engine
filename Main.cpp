#include <SDL/SDL.h>
#include "Core/Level.h"
#include "Test/TestLevel.h"
#include <vector>
int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	Level *currentLevel = new TestLevel();

	currentLevel->begin();

	while (true)
	{
		// Get the next event
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			currentLevel->tick(0.1);

			if (event.type == SDL_QUIT)
			{
				// Break out of the loop on quit
				break;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}