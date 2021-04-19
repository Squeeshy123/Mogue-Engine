#include "RenderManager.h"
SDL_Window* mwindow;
int mindex;
uint32_t mRender_flags;

std::vector<TextureAsset*> render_buffer;

RenderManager::RenderManager(SDL_Window* window, int index, uint32_t flags)
{
	mwindow = window;
	mindex = index;
	mRender_flags = flags;
}

RenderManager::~RenderManager()
{
	SDL_DestroyRenderer(renderer);
}

void RenderManager::DrawRectangle(int x, int y, int w, int h)
{
	SDL_Rect rect;
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;

	SDL_RenderDrawRect(renderer, &rect);
}



void RenderManager::Begin()
{
	renderer = SDL_CreateRenderer(mwindow, mindex, mRender_flags);
	
	printf("Creating Renderer....\n");
	if (!renderer) {
		printf("Faield to create Renderer!\n");
	}
}

void RenderManager::Tick()
{
	SDL_RenderClear(renderer);
	for (size_t i = 0; i < render_buffer.size(); i++) {
		SDL_RenderCopy(renderer, render_buffer[i]->get_texture(), NULL, render_buffer[i]->get_dimensions());
	}
	SDL_RenderPresent(renderer);
}

void RenderManager::End_Tick()
{
	SDL_SetRenderDrawColor(renderer, 114, 144, 154, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

}

void RenderManager::add_texture_to_buffer(TextureAsset* surface)
{
	render_buffer.push_back(surface);
}

