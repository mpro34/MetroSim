#pragma once

#include "game.hpp"

class GameState
{
public:
	Game* game{ nullptr };

	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handleInput() = 0;
};