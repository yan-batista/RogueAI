#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include <SFML/Graphics.hpp>
#include "Tile.hpp"

class GameMap {
public:
	const int tile_size = 10;
	int map_width;
	int map_height;
	Tile** tiles;
	sf::Font& font;

	GameMap(int width, int height, sf::Font& font);
	~GameMap();
	void render(sf::RenderWindow& window) const;
	bool in_bounds(sf::Vector2f) const;
};

#endif // GAMEMAP_HPP
