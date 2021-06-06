#pragma once
namespace Mogue {
    class RenderDevice {
        public:
            virtual bool load_resources() { return false; }
            virtual void render() {}
            virtual void end_render() {}
            virtual void unload_resources() {}

            RenderDevice() {}
            ~RenderDevice() {
                unload_resources();
            }
    };
}