#pragma once

#include <SFML/Graphics.hpp>
#include "game_state.hpp"

class GameStateStart : public GameState
{
	sf::View view;
	void loadgame();

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateStart(Game* game);
};