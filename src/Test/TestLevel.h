#pragma once
#include "../Core/Level.h"
class TestLevel : public Level{
public:
	TestLevel();

	void begin();
	void tick(float deltaTime);
};