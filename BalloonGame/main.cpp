#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//#include <stdio.h>
#include <iostream>

// Sleep(500);
#include <Windows.h>
#include <synchapi.h>

int main()
{
    int i = 0;

    sf::RenderWindow MainWindow(sf::VideoMode(800,800), "Game");
    MainWindow.setFramerateLimit(60);
    
    sf::Texture texture;
    if (!texture.loadFromFile("balloon.png"))
        return EXIT_FAILURE;
    sf::Sprite BalloonSprite(texture);

    BalloonSprite.setScale(0.25, 0.25);
    BalloonSprite.setPosition(0, 0);

    int MousePositionY = sf::Mouse::getPosition().y;
    int MousePositionX = sf::Mouse::getPosition().x;

    int BalloonX = 0;
    int BalloonY = 0;
    //mX = sf::Mouse::getPosition().x;

    // Main loop
    while (MainWindow.isOpen())
    {
        sf::Event event;
        while (MainWindow.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                MainWindow.close();

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::A) {
                    BalloonSprite.move(-50, 0);
                }
                else if (event.key.code == sf::Keyboard::D) {
                    BalloonSprite.move(50, 0);
                }
                else if (event.key.code == sf::Keyboard::W) {
                    BalloonSprite.move(0, -50);
                }
                else if (event.key.code == sf::Keyboard::S) {
                    BalloonSprite.move(0, 50);
                }
            }
        }

        

        MainWindow.clear();
        MainWindow.draw(BalloonSprite);
        MainWindow.display();

        // Slow down
        i += 1;

        if (i == 20) {
            std::cout << (sf::Mouse::getPosition().x);
            std::cout << "\n";
            std::cout << (sf::Mouse::getPosition().y);
            std::cout << "\n";

            i -= 20;
        }
    }

    return 0;
}
