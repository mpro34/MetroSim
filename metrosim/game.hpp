#pragma once

#include <stack>
#include <SFML/Graphics.hpp>

class GameState;

class Game
{
public:
	// Member Variables
	std::stack<GameState*> states;

	sf::RenderWindow window;

	// Methods
	void pushState(GameState* state);
	
	void popState();

	void changeState(GameState* state);

	GameState* peekState();

	void gameLoop();

	Game();
	
	~Game();
};