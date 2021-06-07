#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "RenderDevice.h"


class OpenGLRenderDevice : public Mogue::RenderDevice {
    private:
        std::vector<std::shared_ptr<RenderObject>> render_objects;
    public:

        std::shared_ptr<RenderObject> add_render_object(RenderObject* robj);
        bool load_resources();
        void tick();
        void unload_resources();
        void render();
        void end_render();

        OpenGLRenderDevice();
        ~OpenGLRenderDevice();
};