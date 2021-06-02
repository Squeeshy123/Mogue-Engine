#pragma once

#include <vector>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Core.h"
#include "Servers/InputServer.h"

class Component;
class Object;
class Level;

namespace Mogue {
	class Component {
		private:
			std::shared_ptr<Object> owner;

		public:
			bool is_enabled;

			virtual void tick(float deltaTime);
			virtual void begin();
			virtual void input(InputEvent event);
			virtual void end_tick();
			virtual void end();

			void set_owner(std::shared_ptr<Object> obj);
			std::shared_ptr<Object> get_owner();
	};

	class Object {
		private:
			std::vector<std::shared_ptr<Component>> components;

		public:
			bool is_enabled;

			template <class ComponentType, typename... Args>
			std::shared_ptr<ComponentType> add_component(Args&&... args);

			virtual void tick(float deltaTime);
			virtual void begin();
			virtual void input(InputEvent event);
			virtual void end_tick();
			virtual void end();
	};

	class Level {
		private:
			std::vector<std::shared_ptr<Object>> objects;

		public:
			bool is_enabled;

			std::shared_ptr<Object> add_object();
			
			std::shared_ptr<Object> get_object(int index);

			virtual void tick(float deltaTime);
			virtual void begin();
			virtual void input(InputEvent event);
			virtual void end_tick();
			virtual void end();
	};

}