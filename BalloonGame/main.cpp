#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

#include <Windows.h>
#include <synchapi.h>

#include "balloon.h"

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

    Sprite balloon = createSmallBalloon(0, 0);

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
