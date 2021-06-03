#include "Editor.h"

#include "Servers/WindowServer.h"
#include "ECS.h"

using namespace Mogue;

GLFWwindow* window = nullptr;

ImGuiTreeNodeFlags scene_hierarchy_flags = ImGuiTreeNodeFlags_OpenOnArrow;
static bool align_label_with_current_x_position = false;
static bool test_drag_and_drop = false;


void show_objects_children(Mogue::Object* obj){
    for(auto& child_object : obj->get_children()) {
        if(ImGui::TreeNodeEx(child_object->get_name().c_str(), scene_hierarchy)){
            show_objects_children(child_object.get());
        }
        ImGui::TreePop();
    }
}

void Editor::begin() {

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
            if(ImGui::BeginListBox("Scene Objects")){
                Mogue::Log("Check 1");
                for(auto& obj : current_scene->get_objects()) {
                    Mogue::Log("Check 2");
                        if (ImGui::TreeNodeEx(obj->get_name().c_str(), scene_hierarchy_flags)) {
                            Mogue::Log("Check 3");
                            show_objects_children(obj.get());
                        }
                        ImGui::TreePop();
                    }
                }
                ImGui::EndListBox();
            }
        }
        
        ImGui::End();
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
