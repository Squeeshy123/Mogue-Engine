#pragma once

#include <GL/glew.h>

#include "RenderDevice.h"


class OpenGLRenderDevice : public Mogue::RenderDevice {
    public:

        bool load_resources();
        void tick();
        void unload_resources();
        void render();
        void end_render();

        OpenGLRenderDevice();
        ~OpenGLRenderDevice();
};