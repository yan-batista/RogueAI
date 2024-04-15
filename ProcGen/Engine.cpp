#include "Engine.hpp"

Engine::Engine(std::vector<Entity> new_entities, Entity& new_player, sf::RenderWindow& new_window, GameMap& game_map)
    : entities(std::move(new_entities)), player(new_player), window(new_window), game_map(game_map) {
}

void Engine::render() {
    window.clear();

    // Render World Map
    game_map.render(window);

    // Render Entities
    for (std::size_t i = 0; i < entities.size(); i++) {
        window.draw(entities[i].getTextDisplay());
    }
    window.draw(player.getTextDisplay());

    window.display();
}

void Engine::handle_events(sf::Event& event) {
    if (event.type == sf::Event::Closed)
        window.close();

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.scancode == sf::Keyboard::Scan::Left) {
            player.move(-1, 0);
        }
        else if (event.key.scancode == sf::Keyboard::Scan::Right) {
            player.move(1, 0);
        }
        else if (event.key.scancode == sf::Keyboard::Scan::Up) {
            player.move(0, -1);
        }
        else if (event.key.scancode == sf::Keyboard::Scan::Down) {
            player.move(0, 1);
        }
    }
}
