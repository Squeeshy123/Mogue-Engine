#pragma once


#include <vector>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Core.h"
#include "Servers/ServerManager.h"
#include "Servers/WindowServer.h"
#include "Servers/InputServer.h"
#include "WorldManager.h"

#define init_component_h(comp_name, comp_id, display_name)     \
private: 												       \
	const static int id;		 						       \
public: 												       \
	const static std::string name; 		       				   \
	comp_name() = default; static int get_id() { return id; }  \

#define init_component_cpp(class_name, comp_id, display_name)\
const std::string class_name::name = display_name; 			 \
const int class_name::id = comp_id; 						 \

class Component;
class Object;
class Scene;

namespace Mogue {
	class Component {
		init_component_h(Component, 0, "Component")

		private:
			Object* owner;

		public:
			bool is_enabled;
			const std::string name = "Component";


			virtual void tick(float deltaTime);
			virtual void begin();
			virtual void input(InputEvent event);
			virtual void end_tick();
			virtual void end();
		public:
			Object* get_owner() { return owner; }
			void set_owner(Object* p_owner) { owner = p_owner; }
	};

	class Object {
		private:
			std::vector<std::shared_ptr<Component>> components;
			std::vector<std::shared_ptr<Object>> children;

		public:
			bool is_enabled;

			std::string name;

			void set_name(std::string new_name) {
				name = new_name;
			}
			std::string get_name() {
				return name;
			}

			template <class ComponentType, typename... Args>
			std::shared_ptr<ComponentType> add_component(Args&&... args) {
				std::shared_ptr<ComponentType> c = std::make_shared<ComponentType>();
				c->set_owner(this);
				components.push_back(c);
				return c;
			}

			template <class ComponentType>
			std::shared_ptr<ComponentType> get_component() {
				for(auto& comp : components) {
					if (comp->get_id() == ComponentType::get_id()) {
						return comp;
					}
				}
			}

			template <class ComponentType>
			void remove_component(ComponentType component);
			void remove_component(int index);

			std::vector<std::shared_ptr<Component>> get_components(){
				return components;
			}

			void add_child(Object child);
			std::shared_ptr<Object> create_child();
			std::shared_ptr<Object> get_child(int index);

			std::vector<std::shared_ptr<Object>> get_children() {
				return children;
			}

			virtual void tick(float deltaTime);
			virtual void begin();
			virtual void input(InputEvent event);
			virtual void end_tick();
			virtual void end();
	};

	class Scene {
		private:
			std::vector<std::shared_ptr<Object>> objects;

		public:
			bool is_enabled;

			std::shared_ptr<Object> add_object();
			
			std::shared_ptr<Object> get_object(int index);
			std::vector<std::shared_ptr<Object>> get_objects() {
				return objects;
			}

			virtual void tick(float deltaTime);
			virtual void begin();
			virtual void input(InputEvent event);
			virtual void end_tick();
			virtual void end();

			WindowServer* get_window_server() { return WindowServer::get_singleton(); }
			InputServer*  get_input_server()  { return InputServer::get_singleton();  }
			WorldManager* get_world_manager() { return WorldManager::get_singleton(); }
	
	};
	
}