#include "ServerManager.h"
#include <stdio.h>

namespace Mogue {
	
	ServerManager* ServerManager::singleton = nullptr;


	WindowServer* window_server = WindowServer::get_singleton();


	ServerManager* ServerManager::get_singleton()
	{
		if(ServerManager::singleton != nullptr){
			return ServerManager::singleton;
		} else {
			ServerManager::singleton = new ServerManager();
			return ServerManager::singleton;
		}
	}

	WindowServer* ServerManager::get_window_server() {
		return window_server;
	}
	

	ServerManager::ServerManager()
	{
		ServerManager::singleton = this;
		window_server = WindowServer::get_singleton();
		input         = InputServer::get_singleton();
	}

	

}