#include "Entity.hpp"
#include <iostream>

Entity::Entity(char new_display, sf::Color foreground_color, sf::Font& font, sf::Vector2f new_pos) {
	position = new_pos;

	// define text
	text_display.setFont(font);
	text_display.setString(new_display);
	text_display.setCharacterSize(12);
	text_display.setFillColor(foreground_color);
	text_display.setPosition(new_pos.x, new_pos.y);
}

void Entity::move(int dx, int dy) {
	int const step = 10;

	float dest_x = position.x + (dx * step);
	float dest_y = position.y + (dy * step);

	// use dest_x and dest_y to check if the dest pos is in bounds

	position = sf::Vector2f(dest_x, dest_y);
	text_display.setPosition(position.x, position.y);
}

sf::Text Entity::getTextDisplay() {
	return text_display;
}