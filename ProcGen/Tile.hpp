#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>

// Tile Struct
struct Tile {
    char string_display = ' ';
    bool isWalkable{};
    sf::Vector2f position{};
};

// Tiles
const Tile wallTile = { '#', false, sf::Vector2f(0,0) };
const Tile floorTile = { '.', false, sf::Vector2f(0,0) };

#endif // TILE_HPP