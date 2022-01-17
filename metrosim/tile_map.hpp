#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "tile.hpp"

class TileMap
{
	void dfs(std::vector<TileType>& whitelist,
		sf::Vector2i pos, int label, int type);

public:
	unsigned int width, height;

	std::vector<Tile> tiles;

	/* Resource map */
	std::vector<int> resources;

	unsigned int tileSize, numSelected, numRegions[1];

	/* Load map from disk */
	void load(const std::string& filename, unsigned int width, unsigned int height,
		std::map<std::string, Tile>& tileAtlas);

	/* Save map to disk */
	void save(const std::string& filename);
	
	/* Draw the map */
	void draw(sf::RenderWindow& window, float dt);

	/* Checks if one position in the map is connected to another by only traversing
	tiles in the whitelist */
	void findConnectedRegions(std::vector<TileType> whitelist, int type);

	/* Update the direction of directional tiles so that they face the correct way.
	Used to orient roads, pylons, rivers etc */
	void updateDirection(TileType tileType);

	/* Black map constructor */
	TileMap() :
		tileSize{ 8 }, width{ 0 }, height{ 0 }, numRegions[0]{ 1 } {}
	
	/* Load map from file constructor */
	TileMap(const std::string& filename, unsigned int width, unsigned int height,
		std::map<std::string, Tile>& tileAtlas)
	{
		this->tileSize = 8;
		load(filename, width, height, tileAtlas);
	}
};