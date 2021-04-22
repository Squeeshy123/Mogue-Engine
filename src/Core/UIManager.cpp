#include "Core/UIManager.h"


UIManager::UIManager(SDL_Renderer* renderer, int size_x, int size_y) 
{
	
	ImGui::CreateContext();
	ImGuiSDL::Initialize(renderer, 800, 600);
	ImGui::SetCurrentContext(ImGui::GetCurrentContext());
	
}

UIManager::~UIManager()
{
	ImGuiSDL::Deinitialize();
	ImGui::DestroyContext();
}


void UIManager::tick()
{

	ImGuiIO& currentIO = ImGui::GetIO();
}

ImGuiIO& UIManager::getIO()
{
	return ImGui::GetIO();
}


