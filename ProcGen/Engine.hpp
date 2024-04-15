#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Entity.hpp"
#include "GameMap.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Engine {
	std::vector<Entity> entities;
	Entity& player;
	sf::RenderWindow& window;
	GameMap game_map;

public:
	Engine(std::vector<Entity> new_entities, Entity& new_player, sf::RenderWindow& new_window, GameMap game_map);
	void render();
};

#endif ENGINE_HPP