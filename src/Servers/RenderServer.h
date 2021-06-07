#pragma once
#include "Core.h"

#include "Rendering/RenderDevice.h"
#include "Rendering/OpenGLRenderDevice.h"

#include <memory>

namespace Mogue {
    class RenderServer {
            private:
                std::unique_ptr<RenderDevice> render_device;
            public:					     
                static RenderServer* get_singleton();

                void initialize();
                void tick();
                void end_tick();
                
                std::unique_ptr<RenderDevice> get_render_device();

                ~RenderServer() {

                }
            private:
                static RenderServer* singleton;
            
                
                
                RenderServer() {
                    render_device  = Mogue::make_unique<OpenGLRenderDevice>();
                }
    };
}