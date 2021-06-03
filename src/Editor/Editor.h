#pragma once

#include "Libs/imgui.h"
#include "Libs/imgui_impl_glfw.h"
#include "Libs/imgui_impl_opengl3.h"
#include <stdio.h>

#include "ECS.h"
using namespace Mogue;

class Editor : public Mogue::Scene {
    public:
        Editor();
        ~Editor();

        void begin();
        void tick(float deltaTime);
        void end_tick();
};