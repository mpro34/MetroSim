#pragma once

#include <stack>
#include <SFML/Graphics.hpp>
#include "texture_manager.hpp"
#include "tile.hpp"

class GameState;

class Game
{
	void loadTextures();

	void loadTiles();

public:
	// Member Variables
	const static int tileSize = 8;

	std::stack<GameState*> states;

	sf::RenderWindow window;

	TextureManager texmgr;

	sf::Sprite background;

	std::map<std::string, Tile> tileAtlas;

	// Methods
	void pushState(GameState* state);
	
	void popState();

	void changeState(GameState* state);

	GameState* peekState();

	void gameLoop();

	Game();
	
	~Game();
};