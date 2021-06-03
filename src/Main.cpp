#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Libs/imgui.h"
#include "Libs/imgui_impl_glfw.h"
#include "Libs/imgui_impl_opengl3.h"

#include "Core.h"

#include "Servers/ServerManager.h"
#include "WorldManager.h"

#include "Editor/Editor.h"

using namespace Mogue;

ServerManager* server_manager;
WorldManager* world_manager;

int main(int argc, char *argv[])
{
    server_manager = ServerManager::get_singleton();
    world_manager = WorldManager::get_singleton();

    glewExperimental = true;
    if( !glfwInit() )
    {
        Mogue::Error("Failed to initialize GLFW");
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 2); // Anti Aliasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Load scene from argument, or load editor with -e
    

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

    std::string scene_arg(argv[1]);
    if (scene_arg == "-e") {
        Mogue::Log("Loading Editor...");
        world_manager->load_scene<Editor>();
    }

    world_manager->begin();

    // TICK FUNCTION
    while(WindowServer::get_singleton()->is_running && !glfwWindowShouldClose(WindowServer::get_singleton()->get_window()))
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();
        
        server_manager->tick();
        world_manager->tick(0.1f);
        
        ImGui::Render();
        glClear( GL_COLOR_BUFFER_BIT );

        world_manager->end_tick();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    world_manager->end();

    delete world_manager;
    delete server_manager;
    return 0;
}
