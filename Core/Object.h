#pragma once
#include <vector>
#include "Component.h"
class Object
{
	public:
		Object(std::vector<std::unique_ptr<Component>> comps);
		virtual void begin();
		virtual void tick(float deltaTime);
};

