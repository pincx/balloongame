#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <Windows.h>
#include <synchapi.h>
#include <vector>

#include "bloon.h"
using namespace sf;

int main() {
    // Game states, used for determining what is drawn onscreen
    enum class State {
        MENU, INGAME, PAUSE, END };
    State state = State::MENU;

    // display resolution, used as window size
    Vector2f DisplayResolution;
    DisplayResolution.x =
        VideoMode::getDesktopMode().width / 2;
    DisplayResolution.y =
        VideoMode::getDesktopMode().height / 2;

    // main window, 60 fps limit
    RenderWindow MainWindow(
        VideoMode(DisplayResolution.x, DisplayResolution.y),
        "Game");
    MainWindow.setFramerateLimit(60);
    
	// used to store bloons onscreen
    std::vector<Bloon> bloons;
    Bloon balloon;
    balloon.spawn(5, 5);
    bloons.push_back(balloon);

	// main game loop
    while (MainWindow.isOpen())
    {
        Event event;
        while (MainWindow.pollEvent(event))
        {
            switch (event.type) {
            case Event::Closed:
                MainWindow.close();
            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left) {
                    for (auto& b : bloons) {
                        if (CheckSpriteCollision(b.getSprite(), MainWindow)) {
                            b.hit();
                            std::cout << "hit!\n";
                            std::cout << b.isDead() << "\n";
                        }
                    }
                }
                MainWindow.clear();

				// check if a sprite is "alive" before drawing it
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
            }
        }
    }
}
