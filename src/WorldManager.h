#pragma once

#include "ECS.h"
#include <memory>

namespace Mogue {
    class WorldManager {
        public:
            static WorldManager* get_singleton();

            std::unique_ptr<Level> current_level;

            ~WorldManager();

            void begin();
            void tick(float deltaTime);
            void input(InputEvent event);
            void end_tick();
            void end();
        

		private:
			static WorldManager *singleton;



			WorldManager();
        
    };
}