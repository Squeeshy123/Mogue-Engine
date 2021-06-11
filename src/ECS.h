#pragma once


#include <vector>
#include <memory>

#include "Core.h"
#include "Servers/ServerManager.h"
#include "Servers/WindowServer.h"
#include "Servers/InputServer.h"
#include "WorldManager.h"

#include "Libs/imgui.h"

#define init_component_h(class_name, comp_id)     			   \
private: 												       \
	const static int id;		 						       \
public: 												       \
	const static std::string name; 		       				   \
	class_name() = default; static int get_id() { return id; } \
	static std::string get_name() { return name; } 			   \

#define init_component_cpp(class_name, comp_id, display_name)   \
const  std::string class_name::name = display_name;				\
const  int class_name::id = comp_id;					  		\



namespace Mogue {
	class Component;
	class Object;
	class Scene;
	
	class Component {
		init_component_h(Component, 0)

		private:
			Object* owner;

		public:
			bool is_enabled;


			virtual void tick(float deltaTime) {}
			virtual void begin() {}
			virtual void input(InputEvent event) {}
			virtual void end_tick() {}
			virtual void end() {}

			// this is supposed to list the properties of the component using ImGui
			virtual void list_properties() {}

			Object* get_owner() { return owner; }
			void set_owner(Mogue::Object* p_owner) { owner = p_owner; }


	};

	class Object {
		private:
			std::vector<std::shared_ptr<Component>> components;
			std::vector<std::shared_ptr<Object>> children;

		public:
			~Object() {
				components.clear();
				children.clear();
			}

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
				std::shared_ptr<ComponentType> c = std::make_shared<ComponentType>(std::forward<Args>(args)...);
				c->set_owner(this);
				components.push_back(c);
				return c;
			}

			template <typename CompType>
			CompType* get_component() {
				for(std::shared_ptr<Component> comp : components)
				{
					if (comp.get() != nullptr)
					{
						return dynamic_cast<CompType*>(comp.get());
					}
				}
				return nullptr;
			}

			std::vector<std::shared_ptr<Component>> get_components() {
				return components;
			}

			template <class ComponentType>
			void remove_component(ComponentType component) {
				for(size_t i = 0; i < components.size(); i++)
				{
					if (components[i] == ComponentType::get_id())
						components.erase(components.begin()+i-1);
				}
			}
			void remove_component(int index) {
				components.erase(components.begin()+index-1);
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
			~Scene() {
				objects.clear();
			}

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