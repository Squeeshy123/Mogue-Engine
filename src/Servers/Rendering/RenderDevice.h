#pragma once

#include <vector>
#include <memory>

#include "RenderObject.h"


namespace Mogue {
    class RenderDevice {
        private:
            std::vector<std::shared_ptr<RenderObject>> render_objects;
        public:
            virtual std::shared_ptr<RenderObject> add_render_object(RenderObject* robj) { return false; }
            virtual bool load_resources()                                               { return false; }
            virtual void render()                                                       {}
            virtual void end_render()                                                   {}
            virtual void unload_resources()                                             {}

            RenderDevice() {}
            ~RenderDevice() {
                unload_resources();
            }
    };
}