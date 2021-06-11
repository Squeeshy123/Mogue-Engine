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
                
                RenderDevice* get_render_device(){ 
                    if (render_device != nullptr)
                        return render_device.get(); 
                    return nullptr;
                }

                ~RenderServer() {

                }
            private:
                static RenderServer* singleton;
            
                
                
                RenderServer() {
                    Mogue::Log("Render Server Created");
                    RenderServer::singleton = this;
                    render_device  = Mogue::make_unique<OpenGLRenderDevice>();
                }
    };
}