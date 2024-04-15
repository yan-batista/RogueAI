#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Entity.hpp"
#include "Engine.hpp"
#include "Tile.hpp"
#include "GameMap.hpp"

using namespace std;

int main()
{
    //  CONFIG VARIABLES
    int const screen_width = 800;
    int const screen_height = 600;

    sf::Vector2f player_pos(screen_width / 2, screen_height / 2);

    // WINDOW RENDER AND FONT
    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "Procedural Generation Map");
    sf::Font font;
    if (!font.loadFromFile("Fonts/consola.ttf")) {
        return EXIT_FAILURE;
    }

    // INSTANTIATING
    Entity player('@', sf::Color::White, font, player_pos);
    Entity npc('T', sf::Color::Green, font, sf::Vector2f(100.f,200.f));
    vector<Entity> entities = { npc };
    {
        GameMap game_map(screen_width, screen_height);
        Engine engine(entities, player, window, game_map);

        // MAIN LOOP
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
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

            // RENDER ENTITIES AND PLAYER
            engine.render();
        }
        // End of Scope --> GameMap is deconstructed and data deallocated.

    }

    return 0;
}