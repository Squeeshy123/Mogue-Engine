#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Libs/imgui.h"
#include "Libs/imgui_impl_glfw.h"
#include "Libs/imgui_impl_opengl3.h"

#include "Core.h"

#include "ServerManager.h"

using namespace Mogue;

ServerManager* server_manager;



int main(int argc, char** argv)
{
    server_manager = ServerManager::get_singleton();
    glewExperimental = true;
    if( !glfwInit() )
    {
        Error("Failed to initialize GLFW");
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 2); // Anti Aliasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (server_manager->get_window_server() != nullptr){
        server_manager->get_window_server()->initialize_window();
        if (glewInit() != GLEW_OK) {
            Mogue::Error("Failed to initialize GLEW");
            //return -1;
        }
    }
    else {
        Mogue::Error("Window server is null.");
        return -1;
    }

    glfwSetInputMode(server_manager->get_window_server()->get_window(), GLFW_STICKY_KEYS, GL_TRUE);

    do{
        glClear( GL_COLOR_BUFFER_BIT );


        glfwSwapBuffers(server_manager->get_window_server()->get_window());
        glfwPollEvents();
    }
    while( glfwGetKey(server_manager->get_window_server()->get_window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(server_manager->get_window_server()->get_window()) == 0 );

    return 0;
}
