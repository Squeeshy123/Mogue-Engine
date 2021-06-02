#include "WorldManager.h"

namespace Mogue {

    WorldManager* WorldManager::singleton = nullptr;
    WorldManager* WorldManager::get_singleton() {
		if(WorldManager::singleton == nullptr){
			WorldManager::singleton = new WorldManager();
		}
        return WorldManager::singleton;
	}

    void WorldManager::load_scene(Scene* scene_to_load) {
        
    }

    void WorldManager::begin() {
        if (current_level != nullptr) {
        current_level->begin();
        }
    }
    void WorldManager::tick(float deltaTime) {
        if (current_level != nullptr) {
            current_level->tick(deltaTime);
        }
    }
    void WorldManager::input(InputEvent event) {
        if (current_level != nullptr) {
            current_level->input(event);
        }
    }
    void WorldManager::end_tick() {
        if (current_level != nullptr) {
            current_level->end_tick();
        }
    }
    void WorldManager::end() {
        if (current_level != nullptr) {
            current_level->end();
        }
    }

    WorldManager::WorldManager() {
		WorldManager::singleton = this;
	}
    WorldManager::~WorldManager() {
        
    }

}