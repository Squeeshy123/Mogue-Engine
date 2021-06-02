#pragma once

#include "ECS.h"
#include <memory>

namespace Mogue {
    class WorldManager {
        public:
            static WorldManager* get_singleton();

            std::unique_ptr<Scene> current_level;

            void load_scene(Scene* scene_to_load);

            void begin();
            void tick(float deltaTime);
            void input(InputEvent event);
            void end_tick();
            void end();
        
            ~WorldManager();
		private:
			static WorldManager *singleton;



			WorldManager();
        
    };
}