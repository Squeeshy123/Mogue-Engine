#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Core.h"

#include "Servers/ServerManager.h"
#include "WorldManager.h"

#include "Editor/Editor.h"

void glfw_onError(int error, const char* description)
{

    Mogue::Error("");
}


using namespace Mogue;

ServerManager* server_manager;
WorldManager* world_manager;

int main(int argc, char *argv[])
{
    

    glewExperimental = true;
    if( !glfwInit() )
    {
        Mogue::Error("Failed to initialize GLFW");
    } else {
        Mogue::Log("Initialized GLFW");
        glfwSetErrorCallback(glfw_onError);
    }    

    

    server_manager = ServerManager::get_singleton();
    world_manager = WorldManager::get_singleton();

    if (server_manager->validate_servers()){
        server_manager->initialize();

        
    }
    else {
        Mogue::Error("Some server was not created.");
    }

    

    // Load scene from argument, or load editor with -e
    if (argc > 0){
        std::string scene_arg(argv[1]);
        
        if (scene_arg == "-e") {
            Mogue::Log("Loading Editor...");
            world_manager->load_scene<Editor>();
        }
        else if (scene_arg == "-s" && argc > 1) {
            std::string scene_path(argv[2]);
            // Load scene path here (Requires scene serialisation system!)
        }
    }

    world_manager->begin();

    // TICK FUNCTION
    while(WindowServer::get_singleton()->is_running && !glfwWindowShouldClose(WindowServer::get_singleton()->get_window()))
    {
        
        
        server_manager->tick();

        world_manager->tick(0.1f);
        
        glClear( GL_COLOR_BUFFER_BIT );

        world_manager->end_tick();
        server_manager->end_tick();
    }
    world_manager->end();

    delete world_manager;
    delete server_manager;
    return 0;
}
