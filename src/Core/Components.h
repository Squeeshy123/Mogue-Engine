#pragma once
#include "Core/ECS.h"
#include "Core/TextureManager.h"

class TransformComponent : Component {
	
};

class SpriteComponent : Component {
	public:
		std::string sprite = "C:\\Users\\finnm\\Desktop\\CSCWork\\MogueEngine\\Mogue\\icon.png";
		
	private:
		TextureManager* texture_manager = ;
		TextureAsset* tasset = ;
};