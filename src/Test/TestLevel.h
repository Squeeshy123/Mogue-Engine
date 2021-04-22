#pragma once
#include "../Core/Level.h"
class TestLevel : public Level{
public:
	TestLevel();
	void add_object();
	void begin();
	void tick(float deltaTime);
};