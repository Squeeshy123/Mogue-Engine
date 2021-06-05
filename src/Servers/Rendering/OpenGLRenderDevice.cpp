#include "OpenGLRenderDevice.h"
#include "Servers/ServerManager.h"

#include "Core.h"

#include "Libs/imgui.h"
#include "Libs/imgui_impl_glfw.h"
#include "Libs/imgui_impl_opengl3.h"

GLFWwindow* current_window;

GLfloat triangle_vertices[] = {
	    0.0,  0.8,
	   -0.8, -0.8,
	    0.8, -0.8,
};

GLuint program;
GLint attribute_coord2d;

bool OpenGLRenderDevice::load_resources() {
    if (glewInit() != GLEW_OK) {
        Mogue::Error("Failed to initialize GLEW");
    } else {
        Mogue::Log("Initialized GLEW");
    }

    
	return true;
}

void OpenGLRenderDevice::render() {
    /* Clear the background as white */
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::Render();
	
    glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void OpenGLRenderDevice::unload_resources() {
    glDeleteProgram(program);
}

OpenGLRenderDevice::OpenGLRenderDevice() {
    current_window = Mogue::ServerManager::get_window_server()->get_window();
}
