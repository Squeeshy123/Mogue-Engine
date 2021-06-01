#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Core.h"

namespace Mogue {

    class WindowServer {
        // Singleton
        public:									     
			static WindowServer* get_singleton();		 
            
            void initialize_window();

			GLFWwindow* get_window() { return window; }  

		private:
			static WindowServer* singleton;
			WindowServer();

        
            GLFWwindow* window;

           

    };
}
