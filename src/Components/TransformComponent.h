#pragma once

#include "MogueMath.h"
using namespace Mogue;

class TransformComponent3D {
    init_component(TransformComponent3D, 1)

    Vector3 position{0.0f, 0.0f, 0.0f};
    Vector3 rotation{0.0f, 0.0f, 0.0f};
    Vector3 scale   {1.0f, 1.0f, 1.0f};

    
};