#pragma once
#include "Core.h"

#include "Rendering/RenderDevice.h"
#include "Rendering/OpenGLRenderDevice.h"

#include <memory>

namespace Mogue {
    class RenderServer {
        // Singleton
            public:					     
                static RenderServer* get_singleton();

                void initialize();
                void tick();
                
                ~RenderServer() {

                }
            private:
                static RenderServer* singleton;
            
                std::unique_ptr<RenderDevice> render_device;
                
                RenderServer() {
                    render_device  = Mogue::make_unique<OpenGLRenderDevice>();
                }
    };
}