#include "Editor.h"

#include "Servers/WindowServer.h"
#include "ECS.h"
#include "Components.h"

#include <vector>
#include <string>



#define add_component(classname)                                \
if (objs[current_obj]->get_component<classname>() == nullptr) { \
    objs[current_obj]->add_component<classname>();              \
}                                                               \

using namespace Mogue;

GLFWwindow* window = nullptr;

ImGuiTreeNodeFlags scene_hierarchy_flags = ImGuiTreeNodeFlags_OpenOnArrow;
static bool align_label_with_current_x_position = false;
static bool test_drag_and_drop = false;

static int selection_mask = (1 << 2);
int current_obj = -1;


void show_objects_children(Mogue::Object* obj){
    std::vector<std::shared_ptr<Mogue::Object>> child_objects = obj->get_children();
    for(int o = 0; o<obj->get_children().size(); o++ ) {
        scene_hierarchy_flags = ((o == current_obj) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnArrow;
        if(ImGui::TreeNodeEx(child_objects[o]->get_name().c_str(), scene_hierarchy_flags)){
            show_objects_children(child_objects[o].get());
            ImGui::TreePop();
        }
    }
}

template<class CompType>
bool list_component() {
    return ImGui::Button(CompType::get_name().c_str());
}

void list_components() {
    list_component<TransformComponent3D>();
    list_component<RenderComponent>();
}

void Editor::begin() {
    get_world_manager()->load_scene<Scene>();
}



void Editor::tick(float deltaTime){
    Scene* current_scene = get_world_manager()->get_scene(0);
    
    std::vector<std::shared_ptr<Mogue::Object>> objs;
    if (current_scene == nullptr) {
        
    }
    if (current_scene != nullptr){
        objs = current_scene->get_objects();
    }

    Mogue::Object* selected_obj;
    if (current_obj != -1) selected_obj = objs[current_obj].get();
    //ImGui::ShowDemoWindow();


    { // Scene Editor (Just a debug window for now)
        ImGui::Begin("Scene Editor");
        if (current_scene != nullptr){
            if(current_obj == -1){
                if (ImGui::Button("Add Object to scene")) {
                    current_scene->add_object();
                }
            }
            else {
                if (ImGui::Button("Add Object to object")) {
                    selected_obj->create_child();
                }
            }
        }
        ImGui::End();
    }

    { // Scene Hierarchy TODO: Rewrite for child object support.
        ImGui::Begin("Scene Hierarchy", new bool(true), ImGuiWindowFlags_NoCollapse);
        
        if (current_scene != nullptr) {
            if(ImGui::BeginListBox("", ImVec2(-FLT_MIN, 0))){
                
                for(int o = 0; o < objs.size(); o++) {
                    scene_hierarchy_flags = ((o == current_obj) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnArrow;
                    
                    bool node_open = ImGui::TreeNodeEx((void*)(intptr_t)o, scene_hierarchy_flags, objs[o]->get_name().c_str(), o);
                    
                    if (ImGui::IsItemClicked())
                        current_obj = o;
                    if (test_drag_and_drop && ImGui::BeginDragDropSource())
                    {
                        ImGui::SetDragDropPayload("_TREENODE", NULL, 0);
                        ImGui::Text("This is a drag and drop source");
                        ImGui::EndDragDropSource();
                    }
                    if (node_open)
                    {
                        selected_obj = objs[o].get();
                        show_objects_children(objs[o].get());
                        ImGui::TreePop();
                    }
                        
                    }
                }
                ImGui::EndListBox();
            }
        
        
        ImGui::End();
    }
    
    { // Object properties
        ImGui::Begin("Properties window");
        if (current_obj != -1) {
            { // Object Name
                auto& name = objs[current_obj]->get_name();
                char buffer[256];
                memset(buffer, 0, sizeof(buffer));
                std::strncpy(buffer, name.c_str(), sizeof(buffer));
                if (ImGui::InputText("Name", buffer, sizeof(buffer))) {
                    objs[current_obj]->set_name(std::string(buffer));
                }
            }

            { // List Components
                for(auto& c : objs[current_obj]->get_components()) {
                    c->list_properties();
                }
            }

            { // Add Component button
                if(ImGui::Button("+ Add Component +")){
                    ImGui::OpenPopup("Add Component");
                }
                
                if (ImGui::BeginPopup("Add Component")){
                    if(ImGui::MenuItem("Transform Component 3D")) {
                        add_component(TransformComponent3D);
                        ImGui::CloseCurrentPopup();
                    }
                    if(ImGui::MenuItem("Render Component")) {
                        add_component(RenderComponent);
                        ImGui::CloseCurrentPopup();
                    }
                    ImGui::EndPopup();
                }

                
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

}

Editor::~Editor(){
    
}
