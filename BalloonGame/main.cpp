#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <Windows.h>
#include <synchapi.h>
#include <vector>
#include <string>

#include "bloon.h"
#include "menu.h"
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

    Menu menu;
	menu.New(MainWindow.getSize().x / 4, MainWindow.getSize().y / 2);

    Bloon balloon;
	// main game loop

    while (MainWindow.isOpen())
    {
        if (state == State::INGAME) {
            // bloon spawning
            if (balloon.Random(0, 40, 1)) {
                balloon.spawn(rand() % MainWindow.getSize().x, rand() % MainWindow.getSize().y);
                bloons.push_back(balloon);
            }
        }
        if (state == State::MENU) {
            MainWindow.draw(menu.getSprite());
        }

        MainWindow.display();
        std::cout << (static_cast<int>(state));

        MainWindow.clear();

        // check if a sprite is "alive" before drawing it
        if (state == State::INGAME) {
            for (auto it = bloons.begin(); it != bloons.end();) {
                if (it->isDead()) {
                    it = bloons.erase(it);
                }
                else {
                    MainWindow.draw(it->getSprite());
                    ++it;
                }
            }
        }
        Event event;
        while (MainWindow.pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                MainWindow.close();
                break;

            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left) {
                    if (state == State::INGAME) {
                        for (auto& b : bloons) {
                            if (CheckSpriteCollision(b.getSprite(), MainWindow)) {
                                b.hit();
                                std::cout << "hit!\n";
                                std::cout << b.isDead() << "\n";
                            }
                        }
                    }
                    if (state == State::MENU) {
                        if (CheckSpriteCollision(menu.getSprite(), MainWindow)) {
                            state = State::INGAME;
                        }
                    }
                }
                break;
            }
        }
    }
}