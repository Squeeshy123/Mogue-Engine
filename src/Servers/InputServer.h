#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "WindowServer.h"

namespace Mogue {
	
	enum InputType {
		KEY_EVENT,
		CONTROLLER_EVENT,
		MOUSE_EVENT
	};
	struct InputEvent {
		InputType type;
		int keycode;
		float axis;
	};

	class InputServer
	{
		public:    
			static InputServer* get_singleton();
            
			void initialize();
			void tick();

            bool get_key_down(int keycode);
            static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		
		private:
			static InputServer *singleton;

			InputServer();

	};
}
