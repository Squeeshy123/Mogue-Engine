#include "RenderComponent.h"


using namespace Mogue;

init_component_cpp(RenderComponent, 2, "Render Component")

void RenderComponent::begin() {
    transform = get_owner()->get_component<TransformComponent3D>();
}

void RenderComponent::tick(float deltaTime) {
    std::vector<float> verticies = render_object->verticies;
    for (size_t i = 0; i < verticies.size(); i++)
    {
        if (i % 2 == 0) {
            render_object->verticies[i] = render_object->verticies[i] * transform->position.x;
        } else {
            render_object->verticies[i] = render_object->verticies[i] * transform->position.y;
        }
    }
    
}