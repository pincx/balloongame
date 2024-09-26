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
    enum class State {
        MENU, INGAME, PAUSE, END };

	State state = State::MENU;

    Vector2f DisplayResolution;
    DisplayResolution.x =
        VideoMode::getDesktopMode().width / 2;
    DisplayResolution.y =
        VideoMode::getDesktopMode().height / 2;

    RenderWindow MainWindow(
        VideoMode(DisplayResolution.x, DisplayResolution.y),
        "Game");
    MainWindow.setFramerateLimit(60);

    std::vector<Bloon> bloons;
    Bloon balloon;

    Menu menu;
	menu.New(MainWindow.getSize().x / 4, MainWindow.getSize().y / 2);
    while (MainWindow.isOpen())
    {
        if (state == State::INGAME) {
            if (balloon.Random(0, 40, 1)) {
                balloon.spawn(rand() % MainWindow.getSize().x, rand() % MainWindow.getSize().y);
                bloons.push_back(balloon);
            }
        }
        if (state == State::MENU) {
            MainWindow.draw(menu.getSprite());
        }
        MainWindow.display();
        MainWindow.clear();
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