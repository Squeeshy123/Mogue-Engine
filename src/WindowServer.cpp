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
    
    WindowServer::WindowServer() 
    {
        WindowServer::singleton = this;
    }

    void WindowServer::initialize_window(){
        window = glfwCreateWindow(1280, 720, "Mogue Engine", NULL, NULL);

        if( window == NULL ){
            Mogue::Error( "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the Open GL 2.1." );
            glfwTerminate();
            //return -1;
        }
        
        glfwMakeContextCurrent(window); // Initialize GLEW
        
    }
}