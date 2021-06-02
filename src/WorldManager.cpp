#include "WorldManager.h"

namespace Mogue {
    WorldManager* WorldManager::get_singleton() {
		if(WorldManager::singleton != nullptr){
			return WorldManager::singleton;
		} else {
			WorldManager::singleton = new WorldManager();
			return WorldManager::singleton;
		}
	}

    void WorldManager::begin() {
        current_level->begin();
    }
    void WorldManager::tick(float deltaTime) {
        current_level->tick(deltaTime);
    }
    void WorldManager::input(InputEvent event) {
        current_level->input(event);
    }
    void WorldManager::end_tick() {
        current_level->end_tick();
    }
    void WorldManager::end() {
        current_level->end();
    }
}