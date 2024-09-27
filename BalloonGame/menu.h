#pragma once

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Menu {
private:
	sf::Sprite m_Sprite;
	sf::Texture m_Texture;
public:
	Menu();
	void New(int x, int y);
	sf::Sprite getSprite() const { return m_Sprite; }
};

#endif