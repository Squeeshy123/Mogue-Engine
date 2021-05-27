#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <type_traits>

#include "Debug.h"

#include "Core/RenderServer.h"
#include "Core/TextureServer.h"


class Object;
class Component;
class Manager;

class Component {

		Object* owner;

	public:
		static int id;

		Component() = default;
		Component(Object* p_owner);

		virtual void begin() {};
		virtual void tick(float deltaTime) {};
		virtual void input() {};

		Object* get_object();
		void set_object(Object* obj);

		TextureServer* get_texture_server();
		RenderServer* get_render_server();
		
		static int get_id() { return id;  }
};

class Object {
	private:
		std::vector<std::unique_ptr<Component>> components;
		

		Manager* manager;
		
	public:
		void begin(){
			for(auto& c : components){
				c->begin();
			}
		}
		void tick(float deltaTime) {
			for(auto& c : components){
				c->tick(deltaTime);
			}
		}
		void input(){
			for(auto& c : components){
				c->input();
			}
		}

		template<class ComponentType>
		ComponentType& GetComponent();

		template<class ComponentType>
		bool has_component(){
			return &GetComponent<ComponentType>() != nullptr;
		};

		template <class TComponent, typename... Args>
		void add_component(Args&&... params);

		Manager* get_manager(){ return manager; }
		void set_manager(Manager* m) { manager = m; }

};




class Manager
{
	std::vector<Object*> objects;

	private:
		RenderServer* render_server;
		TextureServer* texture_server;
	public:
		void tick(float deltaTime){
			for(auto& o : objects){
				o->tick(deltaTime);
			}
		}
		void begin(){
			for(auto& o : objects){
				o->begin();
			}
		}
		void input(){
			for(auto& o : objects){
				o->input();
			}
		}

		Object* add_object(){
			Object* o = new Object();
			objects.push_back(o);

			o->set_manager(this);

			return o;
		}

		void set_render_server(RenderServer* rs) { render_server = rs; }
		void set_texture_server(TextureServer* ts) { texture_server = ts; }

		RenderServer* get_render_server() { return render_server; }
		TextureServer* get_texture_server() { return texture_server; }
};




