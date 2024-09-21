// TODO
// Vec2i to str, or just output

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>

int main()
{
    // Main window, load image
    sf::RenderWindow window(sf::VideoMode(200,200), "Game");
    sf::Texture bt;
    if (!bt.loadFromFile("balloon.png"))
        return EXIT_FAILURE;
    sf::Sprite bs(bt);

    bs.setScale(0.25, 0.25);

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

        // Cannot convert from Vector2i to Vector2f
        // bs.move(window.getPosition());

        window.display();
    }

    return 0;
}