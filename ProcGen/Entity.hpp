#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity {
	sf::Text text_display;
	sf::Vector2f position;

public:
	Entity() = default;
	Entity(char new_display, sf::Color foreground, sf::Font& font, sf::Vector2f new_pos);
	void move(int dx, int dy);
	sf::Text getTextDisplay();
};

#endif // ENTITY_HPP