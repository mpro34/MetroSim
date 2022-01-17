#pragma once

#include <SFML/Graphics.hpp>
#include "game_state.hpp"
#include "tile_map.hpp"

enum class ActionState { NONE, PANNING };

class GameStateEditor : public GameState
{
	ActionState actionState;
	sf::View gameView;
	sf::View guiView;
	TileMap map;
	sf::Vector2i panningAnchor;
	float zoomLevel;

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateEditor(Game* game);
};