#pragma once

#ifndef END_H
#define END_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class EndScreen {
private:
	sf::Sprite pSprite;
	sf::Sprite gSprite;
	sf::Sprite qSprite;
	sf::Texture pTexture;
	sf::Texture gTexture;
	sf::Texture qTexture;

	sf::Sprite ReplayGameButtonSprite;
	sf::Sprite CongratulationsSprite;
	sf::Sprite QuitGameSprite;
public:
	EndScreen();
	void New(int x, int y);
	sf::Sprite getPlaySprite() const { return ReplayGameButtonSprite; }
	sf::Sprite getGzSprite() const { return CongratulationsSprite; }
	sf::Sprite getQuitSprite() const { return QuitGameSprite; }
};

#endif