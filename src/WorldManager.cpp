#include "WorldManager.h"
#include "ECS.h"

#include <string>

namespace Mogue {

    WorldManager* WorldManager::singleton = nullptr;
    WorldManager* WorldManager::get_singleton() {
		if(WorldManager::singleton == nullptr){
			WorldManager::singleton = new WorldManager();
		}
        return WorldManager::singleton;
	}
    
    

    void WorldManager::begin() {
        for(auto& scene : active_scenes){
            if (scene != nullptr) {
                scene->begin();
            }
        }
    }
    void WorldManager::tick(float deltaTime) {
        for(auto& scene : active_scenes){
            if (scene != nullptr) {
                scene->tick(deltaTime);
            }
        }
    }
    void WorldManager::input(InputEvent event) {
        for(auto& scene : active_scenes){
            if (scene != nullptr) {
                scene->input(event);
            }
        }
    }
    void WorldManager::end_tick() {
        for(auto& scene : active_scenes){
            if (scene != nullptr) {
                scene->end_tick();
            }
        }
    }
    void WorldManager::end() {
        for(auto& scene : active_scenes){
            if (scene != nullptr) {
                scene->end();
            }
        }
    }

    WorldManager::WorldManager() {
		WorldManager::singleton = this;
	}
    
    WorldManager::~WorldManager() {
        
    }

}