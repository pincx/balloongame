#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <Windows.h>
#include <synchapi.h>
#include <vector>
#include <string>

#include "bloon.h"
#include "menu.h"
#include "end.h"
using namespace sf;

int main() {
    enum class State {
        MENU, INGAME, PAUSE, WEND };
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

    Font font;
	font.loadFromFile("arial.ttf");
	Text text("pincx/BalloonGame", font, 16);
	menu.New(MainWindow.getSize().x / 4, MainWindow.getSize().y / 2);

    EndScreen end;
	end.New(MainWindow.getSize().x / 4, MainWindow.getSize().y / 2);
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

		if (state == State::WEND) {
			MainWindow.draw(end.getPlaySprite());
			MainWindow.draw(end.getQuitSprite());
			MainWindow.draw(end.getGzSprite());
		}

        MainWindow.display();
        MainWindow.clear();
		MainWindow.draw(text);

        if (state == State::INGAME && bloons.size() == 0) {
			state = State::WEND;
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
					if (state == State::WEND) {
						if (CheckSpriteCollision(end.getQuitSprite(), MainWindow)) {
							MainWindow.close();
						}
						if (CheckSpriteCollision(end.getPlaySprite(), MainWindow)) {
							state = State::MENU;
						}
					}
                }
                break;
            }
        }
    }
}