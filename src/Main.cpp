#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Libs/imgui.h"
#include "Libs/imgui_impl_glfw.h"
#include "Libs/imgui_impl_opengl3.h"

#include "Core.h"

#include "Servers/ServerManager.h"
#include "WorldManager.h"

using namespace Mogue;

ServerManager* server_manager;
WorldManager* world_manager;

int main(int argc, char** argv)
{
    server_manager = ServerManager::get_singleton();
    world_manager = WorldManager::get_singleton();

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

    if (server_manager->validate_servers()){
        server_manager->initialize();

        if (glewInit() != GLEW_OK) {
            Mogue::Error("Failed to initialize GLEW");
            return -1;
        }

    }
    else {
        Mogue::Error("Some server was not created.");
        return -1;
    }

    glfwSetInputMode(server_manager->get_window_server()->get_window(), GLFW_STICKY_KEYS, GL_TRUE);

    world_manager->begin();

    // TICK FUNCTION
    while(WindowServer::get_singleton()->is_running && !glfwWindowShouldClose(WindowServer::get_singleton()->get_window()))
    {
        glClear( GL_COLOR_BUFFER_BIT );

        server_manager->tick();
        world_manager->tick();
        
        
        world_manager->end_tick();
    }
    world_manager->end();

    delete server_manager;
    return 0;
}
