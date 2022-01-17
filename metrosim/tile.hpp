#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "animation_handler.hpp"

enum class TileType
{
	VOID = 0,
	GRASS,
	FOREST,
	WATER,
	RESIDENTIAL,
	COMMERCIAL,
	INDUSTRIAL,
	ROAD
};

std::string tileTypeToStr(TileType type);

class Tile
{
public:
	AnimationHandler animHandler;

	sf::Sprite sprite;

	TileType tileType{ TileType::GRASS };

	/* Tile variant, allowing for different looking versions of the same tile */
	int tileVariant{ 0 };

	/* Region IDs of the tile, tiles in the same region are connected. 
		First is for the transport
	*/
	unsigned int regions[1]{ 0 };

	/* Placement cost of the tile */
	unsigned int cost{ 0 };

	/* Current residents / employees */
	double population{ 0.0 };

	/* Maximum population per growth stage / tile variant */
	unsigned int maxPopPerLevel{ 0 };

	/* Maximum number of building levels */
	unsigned int maxLevels{ 1 };

	/* Production output per customer/worker per day, either monetary or goods */
	float production{ 0.0f };

	/* Goods stored */
	float storedGoods{ 0.0f };

	/* Constructor */
	Tile() = default;

	Tile(const unsigned int _tilesize, 
		const unsigned int _height, 
		sf::Texture& _texture,
		const std::vector<Animation>& _animations,
		const TileType _tiletype,
		const unsigned int _cost, 
		const unsigned int _maxpopperlevel,
		const unsigned int _maxlevels)
	{
		this->tileType = _tiletype;
		this->tileVariant = 0;
		this->regions[0] = 0;

		this->cost = _cost;
		this->population = 0;
		this->maxPopPerLevel = _maxpopperlevel;
		this->maxLevels = _maxlevels;
		this->production = 0;
		this->storedGoods = 0;

		this->sprite.setOrigin(sf::Vector2f(0.0f, _tilesize* (_height - 1)));
		this->sprite.setTexture(_texture);
		this->animHandler.frameSize = sf::IntRect(0, 0, _tilesize * 2, _tilesize * _height);
		for (auto animation : _animations)
		{
			this->animHandler.addAnim(animation);
		}
		this->animHandler.update(0.0f);
	}

	void draw(sf::RenderWindow& window, float dt);

	void update();

	/* Return a string containging the display cost of the tile */
	std::string getCost()
	{
		return std::to_string(this->cost);
	}
};
