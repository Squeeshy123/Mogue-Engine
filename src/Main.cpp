#include "Libs/imgui.h"
#include "Libs/imgui_impl_glfw.h"
#include "Libs/imgui_impl_opengl3.h"

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "ServerManager.h"


using namespace Mogue;

static void glfw_error_callback(int error, const char* description)
{
    printf("Glfw Error %d: %s\n", error, description);
}


ServerManager* server_manager = server_manager->get_singleton();

int main(int argc, char** argv)
{

    bool err = gl3wInit() != 0;
    if (err)
    {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return 1;
    }
    // Initialize GLFW
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;


    // Create window with graphics context
    if (server_manager->get_window_server()->get_window() == NULL)
        return 1;


    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(server_manager->get_window_server()->get_window(), true);
    ImGui_ImplOpenGL3_Init();

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    while (!glfwWindowShouldClose(server_manager->get_window_server()->get_window()))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        // Rendering
        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(server_manager->get_window_server()->get_window(), &display_w, &display_h);
        
        glViewport(0, 0, display_w, display_h);
        
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        
        glClear(GL_COLOR_BUFFER_BIT);
        
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(server_manager->get_window_server()->get_window());
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(server_manager->get_window_server()->get_window());
    glfwTerminate();

    return 0;
}
