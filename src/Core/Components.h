#pragma once
#include "Core/ECS.h"
#include "Core/TextureServer.h"

class TransformComponent : Component {
	
};

class SpriteComponent : public Component {
public:
	std::string sprite = "C:\\Users\\finnm\\Desktop\\CSCWork\\MogueEngine\\Mogue\\icon.png";

	SpriteComponent() = default;
	SpriteComponent(std::string SpritePath) { sprite = SpritePath; };
	~SpriteComponent() { delete tasset; };


		void begin(){
			get_render_server()->add_texture_to_buffer(tasset);
		}

	private:
		TextureAsset* tasset = get_texture_server()->create_texture_asset(sprite);
};