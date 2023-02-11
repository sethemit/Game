#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");

    // Load the textures
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("player.png")) {
        std::cout << "Error loading player texture" << std::endl;
        return 1;
    }

    // Create the player sprite
    sf::Sprite player;
    player.setTexture(playerTexture);
    player.setPosition(400, 500);

    // Start the game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Update the player
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-5, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(5, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.move(0, -5);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player.move(0, 5);
        }

        // Clear the window
        window.clear();

        // Draw the player
        window.draw(player);

        // Display the window
        window.display();
    }

    return 0;
}