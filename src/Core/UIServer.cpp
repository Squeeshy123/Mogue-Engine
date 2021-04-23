#include "Core/UIServer.h"


UIServer::UIServer(SDL_Renderer* renderer, int size_x, int size_y) 
{
	
	ImGui::CreateContext();
	ImGuiSDL::Initialize(renderer, 800, 600);
	ImGui::SetCurrentContext(ImGui::GetCurrentContext());
	
}

UIServer::~UIServer()
{
	ImGuiSDL::Deinitialize();
	ImGui::DestroyContext();
}


void UIServer::tick()
{

	ImGuiIO& currentIO = ImGui::GetIO();
}

ImGuiIO& UIServer::getIO()
{
	return ImGui::GetIO();
}


