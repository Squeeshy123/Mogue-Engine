#pragma once

#include "ECS.h"
#include "RenderObject.h"
#include "TransformComponent.h"

#include <memory>

using namespace Mogue;

class RenderComponent : public Mogue::Component {
    init_component(RenderComponent, 2)
    private:
        std::shared_ptr<RenderObject> render_object = RenderServer::get_singleton()->get_render_device()->add_render_object(new RenderObject());
        std::shared_ptr<TransformComponent3D> transform;

    public:
      void begin();
        void tick(float deltaTime);
};