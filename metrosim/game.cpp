//#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "game.hpp"
#include "game_state.hpp"

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

void Game::gameLoop()
{
	sf::Clock clock;

	while (this->window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update(dt);
		this->window.clear(sf::Color::Black);
		peekState()->draw(dt);
		this->window.display();
	}
}

Game::Game()
{
	this->window.create(sf::VideoMode(800, 600), "Metro Sim");
	this->window.setFramerateLimit(60);
}

Game::~Game()
{
	while (!this->states.empty()) popState; // Clear all cached state
}