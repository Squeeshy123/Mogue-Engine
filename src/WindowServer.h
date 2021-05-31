#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Core.h"
namespace Mogue {

    class WindowServer {
        init_singleton(WindowServer)
        private:
            GLFWwindow* window = glfwCreateWindow(1280, 720, "Mogue Engine", NULL, NULL);
        public:
            GLFWwindow* get_window() { return window; }

    };

}
