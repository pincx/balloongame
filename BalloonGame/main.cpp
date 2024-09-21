#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <stdio.h>

#include <windows.h>
#include <synchapi.h>

int main()
{
    // Main window, load image
    sf::RenderWindow window(sf::VideoMode(200,200), "Game");
    sf::Texture bt;
    if (!bt.loadFromFile("balloon.png"))
        return EXIT_FAILURE;
    sf::Sprite bs(bt);

    bs.setScale(0.25, 0.25);

    //mX = sf::Mouse::getPosition().x;

    // Main loop

    while (window.isOpen())
    {
        // SetTimer(NULL, 0, 1000, NULL);
        Sleep(1000);
    

        printf("%s\n", sf::Mouse::getPosition().x);
        printf("%s\n", sf::Mouse::getPosition().y);
    }

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