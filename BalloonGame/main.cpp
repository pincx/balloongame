#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//#include <stdio.h>
#include <iostream>

// Sleep(500);
#include <Windows.h>
#include <synchapi.h>

#include "balloon.h"
#include "mouse.h"

using namespace sf;

int main()
{
    enum class State {
        MENU, INGAME, PAUSE
    };

    State state = State::MENU;

    Vector2f DisplayResolution;

    DisplayResolution.x =
        VideoMode::getDesktopMode().width / 4;
    DisplayResolution.y =
        VideoMode::getDesktopMode().height / 4;

    int i = 0;

    RenderWindow MainWindow(
        VideoMode(DisplayResolution.x, DisplayResolution.y),
        "Game");
    MainWindow.setFramerateLimit(60);
    


    int MousePositionY = Mouse::getPosition().y;
    int MousePositionX = Mouse::getPosition().x;

    int BalloonX = 0;
    int BalloonY = 0;
    //mX = Mouse::getPosition().x;

    Sprite balloon = createSmallBalloon(0, 0);
    // Main loop
    while (MainWindow.isOpen())
    {
        Event event;
        while (MainWindow.pollEvent(event))
        {
            switch (event.type) {
            case Event::Closed:
                MainWindow.close();

            case Event::MouseButtonPressed:
                std::cout << (CheckSpriteCollision(balloon, MainWindow));
            }
        }

        

        MainWindow.clear();
        MainWindow.draw(balloon);
        MainWindow.display();

        // Slow down
        i += 1;

        /*if (i == 20) {
            std::cout << (Mouse::getPosition().x);
            std::cout << "\n";
            std::cout << (Mouse::getPosition().y);
            std::cout << "\n";

            i -= 20;
        */
        }
    
    return 0;
}