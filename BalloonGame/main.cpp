// TODO
// Vec2i to str, or just output

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>

int main()
{
    // Main window, load image
    sf::RenderWindow window(sf::VideoMode(800,800), "Game");
    sf::Texture bt;
    if (!bt.loadFromFile("balloon.png"))
        return EXIT_FAILURE;
    sf::Sprite bs(bt);

    // Grab mouse position, need to print to console
    sf::Vector2i mp = window.getPosition();

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(bs);
        window.display();
    }

    return 0;
}