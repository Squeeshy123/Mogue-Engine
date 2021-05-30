#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Core.h"

class WindowServer {
    private:
        GLFWwindow* window = glfwCreateWindow(1280, 720, "Mogue Engine", NULL, NULL);
    init_singleton(WindowServer)
}