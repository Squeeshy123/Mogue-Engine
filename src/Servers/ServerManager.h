#pragma once
#include "Core.h"

#include "Servers/WindowServer.h"

#include "Servers/InputServer.h"

namespace Mogue {
	class ServerManager
	{
		public:
			static ServerManager* get_singleton();

			bool validate_servers();

			void initialize();
			void tick();

			static WindowServer*  get_window_server();
			static InputServer*   get_input_server();

			~ServerManager();
		private:
			static ServerManager *singleton;



			ServerManager();
			

	};
}
