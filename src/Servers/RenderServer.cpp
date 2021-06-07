#include "RenderServer.h"

bool tick_device = false;
namespace Mogue {
    RenderServer* RenderServer::singleton = nullptr;

    RenderServer* RenderServer::get_singleton() {
        if(RenderServer::singleton == nullptr){
            RenderServer::singleton = new RenderServer();
        }
        return RenderServer::singleton;
    }

    std::unique_ptr<RenderDevice> RenderServer::get_render_device() 
    { return render_device; }

    void RenderServer::initialize() {
        if (render_device != nullptr){
            if (render_device->load_resources()) {
                tick_device = true;
            }
        } else {
            render_device = Mogue::make_unique<OpenGLRenderDevice>();
            if (render_device->load_resources()) {
                tick_device = true;
            }
        }
    }

    void RenderServer::tick() {
        if (tick_device) {
            render_device->render();
        }
    }
    void RenderServer::end_tick(){
        if (tick_device) {
            render_device->end_render();
        }
    }
}