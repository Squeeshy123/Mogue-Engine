#include "ServerManager.h"
#include <stdio.h>

namespace Mogue {
	
	ServerManager* ServerManager::singleton = nullptr;

	WindowServer* window_server = WindowServer::get_singleton();
	InputServer*  input = InputServer::get_singleton();
	RenderServer* render_server = RenderServer::get_singleton();


	ServerManager* ServerManager::get_singleton() {
		if(ServerManager::singleton != nullptr){
			return ServerManager::singleton;
		} else {
			ServerManager::singleton = new ServerManager();
			return ServerManager::singleton;
		}
	}

	bool ServerManager::validate_servers(){
		bool input_valid = input != nullptr;
		bool window_valid = window_server != nullptr;
		bool renderer_valid = render_server != nullptr;
		return input_valid && window_valid && renderer_valid;
	}

	WindowServer* ServerManager::get_window_server() {
		return window_server;
	}
	InputServer* ServerManager::get_input_server(){
		return input;
	}

	void ServerManager::initialize(){
		window_server->initialize();
		input->initialize();
		render_server->initialize();
	}

	void ServerManager::tick(){
		window_server->tick();
		input->tick();
		render_server->tick();
	}

	void ServerManager::end_tick() {
		render_server->end_tick();
	}


	ServerManager::ServerManager() {
		ServerManager::singleton = this;
		window_server = WindowServer::get_singleton();
		input         = InputServer::get_singleton();
		render_server = RenderServer::get_singleton();
	}

	ServerManager::~ServerManager() {
		delete input;
		delete render_server;
		delete window_server;
	}

}