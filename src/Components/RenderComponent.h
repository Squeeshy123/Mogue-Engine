#pragma once

#include "ECS.h"
#include "RenderObject.h"
#include "TransformComponent.h"

#include <memory>


class RenderComponent : public Mogue::Component {
    
    init_component_h(RenderComponent, 2);
    private:
        std::shared_ptr<RenderObject> render_object = RenderServer::get_singleton()->get_render_device()->add_render_object(new RenderObject());
        TransformComponent3D* transform;

    public:
        void begin();
        void tick(float deltaTime);
        void list_properties();
};