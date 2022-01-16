// metrosim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "game.hpp"

/*
	@brief - Create the state manager and then start the game loop.
*/
int main()
{
	Game game;

	game.gameLoop();

	return 0;
}