#pragma once
#include "Core.h"

#include "WindowServer.h"

namespace Mogue {
	class ServerManager
	{
		init_singleton(ServerManager)

		private:
			WindowServer* window_server = WindowServer::get_singleton();

		public:
			WindowServer* get_window_server() { return window_server; }

		
	};
}
