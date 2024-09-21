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
    //mX = sf::Mouse::getPosition().x;

    // Main loop
    while (MainWindow.isOpen())
    {
        sf::Event event;
        while (MainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                MainWindow.close();
        }
        switch(event.type ==)
        

        MainWindow.clear();
        MainWindow.draw(BalloonSprite);
        BalloonSprite.move(float(MousePositionX), float(MousePositionY));
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
