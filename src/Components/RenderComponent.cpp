#include "RenderComponent.h"


using namespace Mogue;

init_component_cpp(RenderComponent, 2, "Render Component");

void RenderComponent::begin() {
    Mogue::Log("Began render component");
}

void RenderComponent::list_properties() {
    list_default_properties("Render Component");
}

void RenderComponent::tick(float deltaTime) {
    Mogue::Log("tick render component");
    std::vector<float> verticies = render_object->verticies;
    if (transform != nullptr){
        
        for (size_t i = 0; i < verticies.size(); i++)
        {
            printf("%f", render_object->verticies[i]);
            if (i % 2 == 0) {
                
                render_object->verticies[i] = render_object->verticies[i] * transform->position.x;
            } else {
                render_object->verticies[i] = render_object->verticies[i] * transform->position.y;
            }
        }
    } else{
        transform = get_owner()->get_component<TransformComponent3D>();
    }
}