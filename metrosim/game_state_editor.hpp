#pragma once

#include <SFML/Graphics.hpp>
#include "game_state.hpp"

class GameStateEditor : public GameState
{
	sf::View gameView;
	sf::View guiView;

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateEditor(Game* game);
};