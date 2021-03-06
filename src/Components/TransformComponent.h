#pragma once
#include "TransformComponent.h"

#include <string>

#include "ECS.h"
#include "MogueMath.h"


using namespace Mogue;

class TransformComponent3D : public Mogue::Component{
    init_component_h(TransformComponent3D, 1)

    public:
        Vector3 position{0.0f, 0.0f, 0.0f};
        Vector3 rotation{0.0f, 0.0f, 0.0f};
        Vector3 scale{1.0f, 1.0f, 1.0f};

        void list_properties();
};