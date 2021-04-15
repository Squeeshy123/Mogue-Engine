#include "RenderComponent.h"
#include <stdio.h>
#include <SDL/SDL.h>



SDL_Renderer* renderer;

void RenderComponent::tick(float deltaTime)
{
	printf("Hello, I'm a Render component!\n");

	SDL_Rect* rect = new SDL_Rect();
	rect->x = 0;
	rect->y = 0;
	rect->w = 10;
	rect->h = 10;
	SDL_RenderDrawRect(renderer, rect);
}
