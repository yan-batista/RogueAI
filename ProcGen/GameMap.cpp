#include "GameMap.hpp"

GameMap::GameMap(int width, int height) : map_width(width), map_height(height) {
    int number_of_tiles_width = map_width / tile_size;
    int number_of_tiles_height = map_height / tile_size;

    tiles = new Tile * [number_of_tiles_width];
    for (int i = 0; i < number_of_tiles_width; ++i) {
        tiles[i] = new Tile[number_of_tiles_height];
    }

    // Fill the tiles array with wall tiles
    for (int i = 0; i < number_of_tiles_width; ++i) {
        for (int j = 0; j < number_of_tiles_height; ++j) {
            Tile _floorTile = floorTile;
            _floorTile.position = sf::Vector2f(i * float(tile_size), j * (float)tile_size);
            tiles[i][j] = _floorTile;
        }
    }
}

GameMap::~GameMap() {
    // Clean up: deallocate memory
    for (int i = 0; i < map_width / tile_size; ++i) {
        delete[] tiles[i];
    }
    delete[] tiles;
}

bool GameMap::in_bounds(sf::Vector2f position) const {
	return (position.x < map_width || position.x > map_width) && (position.y < map_height || position.y > map_height);
}

void GameMap::render(sf::RenderWindow& window) const {
    for (int i = 0; i < map_width / 10; i++) {
        for (int j = 0; j < map_height / 10; j++) {
            sf::Text display;
            display.setString(tiles[i][j].string_display);
            display.setFont(font);
            display.setCharacterSize(12);
            display.setFillColor(sf::Color::White);
            display.setPosition(tiles[i][j].position);
            window.draw(display);
        }
    }
}

