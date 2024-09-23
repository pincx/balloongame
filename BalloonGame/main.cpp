#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <Windows.h>
#include <synchapi.h>
#include <vector>

#include "bloon.h"
using namespace sf;

int main() {
    enum class state {
        MENU, INGAME, PAUSE, END
    };
    state state = state::INGAME;
    Vector2f DisplayResolution;
    DisplayResolution.x =
        VideoMode::getDesktopMode().width / 2;
    DisplayResolution.y =
        VideoMode::getDesktopMode().height / 2;

    int i = 0;

    RenderWindow MainWindow(
        VideoMode(DisplayResolution.x, DisplayResolution.y),
        "Game");
    MainWindow.setFramerateLimit(60);

    std::vector<Bloon> bloons;
    Bloon balloon;
    balloon.spawn(5, 5);
    bloons.push_back(balloon);

    while (MainWindow.isOpen())
    {
        Event event;
        while (MainWindow.pollEvent(event))
        {
            switch (event.type) {
            case Event::Closed:
                MainWindow.close();

                MainWindow.clear();

                if (state == state::INGAME) {
                    for (auto& b : bloons) {
                        b.getSprite().move(0.1f, 0.1f);
                    }
            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left) {
                    if (event.mouseButton.button == Mouse::Left) {
                        for (auto& b : bloons) {
                            if (CheckSpriteCollision(b.getSprite(), MainWindow)) {
                                b.hit();
                                std::cout << "hit!\n";
                                std::cout << b.isDead() << "\n";
                            }
                        }
                    }
                }


                // Create an if statement that only draws the sprite if it is not dead
                // only draw sprite if it is alive


                for (auto it = bloons.begin(); it != bloons.end();) {
                    if (it->isDead()) {
                        it = bloons.erase(it);
                    }
                    else {
                        MainWindow.draw(it->getSprite());
                        ++it;
                    }
                }
                MainWindow.display();

                // Slow down
                //i += 1;

                /*if (i == 20) {
                    std::cout << (Mouse::getPosition().x);
                    std::cout << "\n";
                    std::cout << (Mouse::getPosition().y);
                    std::cout << "\n";

                    i -= 20;
                */
                }
            }
        }
    }
}