#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Core.h"

namespace Mogue {

    class WindowServer {
        // Singleton
        public:					     
			static WindowServer* get_singleton();		 
            
            bool is_running;

            void initialize();
            void tick();
            
			GLFWwindow* get_window() { return window; }  
            void quit_window();
            
            ~WindowServer();

		private:
			static WindowServer* singleton;
			
            GLFWwindow* window;
        
            
            WindowServer();
    };
}
