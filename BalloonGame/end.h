#pragma once

#ifndef END_H
#define END_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class EndScreen {
private:
	sf::Sprite play_Sprite;
	sf::Sprite gz_Sprite;
	sf::Sprite quit_Sprite;
	sf::Texture play_Texture;
	sf::Texture gz_Texture;
	sf::Texture quit_Texture;
public:
	EndScreen();
	void New(int x, int y);
	bool isActive() const { return m_isActive; };
	sf::Sprite getPlaySprite() const { return play_Sprite; }
	sf::Sprite getGzSprite() const { return gz_Sprite; }
	sf::Sprite getQuitSprite() const { return quit_Sprite; }
};

#endif