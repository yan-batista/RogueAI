#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>

//class Tile {
//	int const tile_size = 10;
//public:
//	bool isWalkable;
//	sf::Vector2f position;
//	sf::Text display;
//
//	Tile() = default; // Default Constructor
//	Tile(Tile&&) noexcept; // Move Constructor
//	Tile(bool, sf::Vector2f, char, sf::Color, sf::Font&); // Constructor
//	void setTilePosition(sf::Vector2f);
//	void setCharacter(char);
//};

// Tile Struct
struct Tile {
    char string_display{};
    bool isWalkable{};
    sf::Vector2f position{};
};

// Tiles
const Tile wallTile = { '#', false, sf::Vector2f(0,0) };
const Tile floorTile = { '.', false, sf::Vector2f(0,0) };

#endif // TILE_HPP