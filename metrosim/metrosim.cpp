// metrosim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "game.hpp"
#include "game_state_start.hpp"

/*
	@brief - Create the state manager and then start the game loop.
*/
int main()
{
	Game game;

	game.pushState(new GameStateStart(&game));

	game.gameLoop();

	return 0;
}