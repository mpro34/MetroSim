#pragma once

#include <stack>
#include <SFML/Graphics.hpp>
#include "texture_manager.hpp"

class GameState;

class Game
{
	void loadTextures();

public:
	// Member Variables
	std::stack<GameState*> states;

	sf::RenderWindow window;

	TextureManager texmgr;

	sf::Sprite background;

	// Methods
	void pushState(GameState* state);
	
	void popState();

	void changeState(GameState* state);

	GameState* peekState();

	void gameLoop();

	Game();
	
	~Game();
};