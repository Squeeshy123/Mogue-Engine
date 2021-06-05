#pragma once
#include "Rendering/RenderingDevice.h"
#include "Rendering/OpenGLRenderDevice.h"

#include <memory>

class RenderServer {
    // Singleton
        public:					     
			static RenderServer* get_singleton();

            void initialize();
            void tick();
            
            ~RenderServer();
		private:
			static RenderServer* singleton;
		
            std::unique_ptr<RenderDevice> active_render_device;
            
            RenderServer() {
                active_render_device = std::make_unique<OpenGLRenderDevice>();
            }
};