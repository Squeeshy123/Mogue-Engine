#pragma once

#include "Core/ECS.hpp"
#include "Core/TextureServer.h"

class TransformComponent : public Component {
	int pos_x;
	int pos_y;

};

class SpriteComponent : public Component {

	private:
		TextureAsset* t_asset;
	
	public:
		std::string sprite_path = "C:\\Users\\finnm\\Desktop\\CSCWork\\MogueEngine\\Mogue\\icon.png";
		
		SpriteComponent(std::string p_path);

		void begin();


};