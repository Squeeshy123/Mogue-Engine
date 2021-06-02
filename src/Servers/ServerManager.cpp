#include "ServerManager.h"
#include <stdio.h>

namespace Mogue {
	
	ServerManager* ServerManager::singleton = nullptr;

	WindowServer* window_server = WindowServer::get_singleton();
	InputServer*  input = InputServer::get_singleton();


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
		return input_valid && window_valid;
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
	}

	void ServerManager::tick(){
		window_server->tick();
		input->tick();
	}




	ServerManager::ServerManager() {
		ServerManager::singleton = this;
		window_server = WindowServer::get_singleton();
		input         = InputServer::get_singleton();
	}

	ServerManager::~ServerManager() {
		delete input;
		//Clear render server memory here.
		delete window_server;
	}

}