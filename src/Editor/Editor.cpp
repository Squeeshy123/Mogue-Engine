#include "Editor.h"

#include "Servers/WindowServer.h"

using namespace Mogue;

GLFWwindow* window = nullptr;

void show_objects_children(Object* obj){
    for(auto& child_object : obj->get_children()) {
        if(ImGui::CollapsingHeader(obj->get_name().c_str())){
            show_objects_children(obj);
        }
    }
}


void Editor::tick(float deltaTime){
    Scene* current_scene = get_world_manager()->get_scene(0);
    
    
    {
        ImGui::Begin("Scene Editor");
        if (ImGui::Button("Add Object to scene") && current_scene != nullptr) {
            current_scene->add_object();
        }
        ImGui::End();
    }

    {
        ImGui::Begin("Scene Hierarchy");
        if (current_scene == nullptr) {
            ImGui::Text("No scenes active!");
            if (ImGui::Button("Create a scene")) {
                get_world_manager()->load_scene<Scene>();
            }
        }
        else {
            if(ImGui::BeginListBox("Objects")){
                for(auto& obj : current_scene->get_objects()) {
                    if (ImGui::CollapsingHeader(obj->get_name().c_str())) {
                        
                    }
                }
                ImGui::EndListBox();
            }
        }
        
        ImGui::End();
    }
}

void Editor::end_tick(){
    
}


Editor::Editor() {
    Mogue::Log("Loaded Editor!");

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    window = WindowServer::get_singleton()->get_window();

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();
}

Editor::~Editor(){
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
