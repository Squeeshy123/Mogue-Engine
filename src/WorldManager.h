#pragma once

#include <memory>
#include <vector>

#include "Servers/InputServer.h"

namespace Mogue {
    class Scene;

    class WorldManager {

        private:
            std::vector<std::shared_ptr<Mogue::Scene>> active_scenes;
        public:
            static WorldManager* get_singleton();

            

            

            template<class SceneClass>
            Scene* load_scene() {
                std::shared_ptr<SceneClass> scn = std::make_shared<SceneClass>();
                active_scenes.push_back(scn);
                active_scenes[active_scenes.size()-1]->begin();
                return active_scenes[active_scenes.size()-1].get();
            }

            Scene* get_scene(int index){
                if (index < active_scenes.size()-1){
                    if(active_scenes[index] != nullptr){
                        return active_scenes[index].get();
                    } 
                    else {
                        Warning("Scene does not exist");
                        return nullptr;
                    }
                } 
                else {
                    Warning("Scene Index out of range");
                    return nullptr;
                }
            }

            std::vector<std::shared_ptr<Mogue::Scene>> get_active_scenes() {
                return active_scenes;
            }
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