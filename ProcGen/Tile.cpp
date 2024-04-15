//#include "Tile.hpp"
//
//Tile::Tile(bool walkable, sf::Vector2f pos, char new_char, sf::Color color, sf::Font& font) {
//	isWalkable = walkable;
//	position = pos;
//
//	display.setFont(font);
//	display.setCharacterSize(12);
//	display.setFillColor(color);
//
//	setCharacter(new_char);
//}
//
//Tile::Tile(Tile&& other) noexcept : isWalkable(other.isWalkable), position(other.position), display(std::move(other.display)) {}
//
//void Tile::setTilePosition(sf::Vector2f new_pos) {
//	display.setPosition(new_pos);
//}
//
//void Tile::setCharacter(char new_char) {
//	display.setString(new_char);
//}