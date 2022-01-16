//#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "game.hpp"
#include "game_state.hpp"
#include "animation_handler.hpp"


/*
	@brief - Fill the member texture manager with input textures.
*/
void Game::loadTextures()
{
	texmgr.loadTexture("grass", "media/grass.png");
	texmgr.loadTexture("forest", "media/forest.png");
	texmgr.loadTexture("water", "media/water.png");
	texmgr.loadTexture("residential", "media/residential.png");
	texmgr.loadTexture("commercial", "media/commercial.png");
	texmgr.loadTexture("industrial", "media/industrial.png");
	texmgr.loadTexture("road", "media/road.png");
	texmgr.loadTexture("background", "media/background.png");
}

/*
	@brief - Populate the tile atlas map which maps a string to a Tile.
*/
void Game::loadTiles()
{
	Animation staticAnim(0, 0, 1.0f);

	tileAtlas["grass"] = Tile(
		tileSize, 1, texmgr.getRef("grass"),
		{ staticAnim }, TileType::GRASS, 50, 0, 1
	);

	tileAtlas["forest"] = Tile(
		tileSize, 1, texmgr.getRef("forest"),
		{ staticAnim }, TileType::FOREST, 100, 0, 1
	);

	tileAtlas["water"] = Tile(
		tileSize, 1, texmgr.getRef("water"),
		{ Animation(0, 3, 0.5f),
		Animation(0, 3, 0.5f),
		Animation(0, 3, 0.5f) },
		TileType::WATER, 0, 0, 1
	);

	tileAtlas["residential"] = Tile(
		tileSize, 2, texmgr.getRef("residential"),
		{ staticAnim, staticAnim, staticAnim,
		staticAnim, staticAnim, staticAnim, },
		TileType::RESIDENTIAL, 300, 50, 6
	);

	tileAtlas["commercial"] = Tile(
		tileSize, 2, texmgr.getRef("commercial"),
		{ staticAnim, staticAnim, staticAnim, staticAnim, },
		TileType::COMMERCIAL, 300, 50, 4
	);

	tileAtlas["industrial"] = Tile(
		tileSize, 2, texmgr.getRef("industrial"),
		{ staticAnim, staticAnim, staticAnim, staticAnim, },
		TileType::INDUSTRIAL, 300, 50, 4
	);

	tileAtlas["road"] = Tile(
		tileSize, 1, texmgr.getRef("road"),
		{ staticAnim, staticAnim, staticAnim, staticAnim,
		staticAnim, staticAnim, staticAnim, staticAnim,
		staticAnim, staticAnim, staticAnim, },
		TileType::ROAD, 100, 0, 1
	);
}

/*
	@brief - push input game state onto states cache.
*/
void Game::pushState(GameState* state)
{
	this->states.push(state);
}

/*
	@brief - pop a game state from cache and delete it.
*/
void Game::popState()
{
	delete this->states.top();
	this->states.pop();
}

/*
	@brief - change the top-level game state to the input one.
*/
void Game::changeState(GameState* state)
{
	if (!this->states.empty())
	{
		popState();
	}
	pushState(state);
}

/*
	@brief - view the topmost game state.
*/
GameState* Game::peekState()
{
	if (this->states.empty()) return nullptr;
	return this->states.top();
}

/*
	@brief - main game loop
*/
void Game::gameLoop()
{
	sf::Clock clock;

	while (this->window.isOpen())
	{
		sf::Time elapsed = clock.restart(); // return the time since clock started.
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update(dt);
		this->window.clear(sf::Color::Black);
		peekState()->draw(dt);
		this->window.display();
	}
}

/*
	@brief - Create a new window and rate limit to 60 fps.
*/
Game::Game()
{
	this->loadTextures(); // Load all textures

	this->loadTiles(); // Load all tiles from the loaded textures

	this->window.create(sf::VideoMode(800, 600), "Metro Sim");
	this->window.setFramerateLimit(60);

	// Set specific textures once they are loaded and the window is ready.
	this->background.setTexture(this->texmgr.getRef("background"));
}

/*
	@brief - Clear all cached state
*/
Game::~Game()
{
	while (!this->states.empty()) popState;
}