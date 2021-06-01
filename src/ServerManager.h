#pragma once
#include "Core.h"

#include "WindowServer.h"

//#include "WindowServer.h"

namespace Mogue {
	class ServerManager
	{
		public:
								     
			static ServerManager* get_singleton();

			static WindowServer* get_window_server();

		private:								     
			static ServerManager *singleton;


			ServerManager();

	};
}
