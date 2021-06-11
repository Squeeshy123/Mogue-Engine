#include "WindowServer.h"

namespace Mogue {
    WindowServer* WindowServer::singleton = nullptr;

    WindowServer* WindowServer::get_singleton()
    {
        if (WindowServer::singleton != nullptr) {
            return WindowServer::singleton;
        }
        else {
            WindowServer::singleton = new WindowServer();
            return singleton;
        }
    }

    void WindowServer::initialize(){
        window = glfwCreateWindow(1280, 720, "Mogue Engine", NULL, NULL);
        is_running = true;

        glfwWindowHint(GLFW_SAMPLES, 2); // Anti Aliasing
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

        if( window == NULL ){
            Mogue::Error( "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the Open GL 2.1." );
            glfwTerminate();
            //return -1;
        }
        
        glfwMakeContextCurrent(window); // Initialize GLEW
    }

    void WindowServer::quit_window(){
        is_running = false;
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    void WindowServer::tick(){
        glfwSwapBuffers(window);
    }

    WindowServer::WindowServer() 
    {
        Mogue::Log("Window Server Created");
        WindowServer::singleton = this;
    }
    WindowServer::~WindowServer()
    {
        quit_window();
        glfwDestroyWindow(window);
    }
}