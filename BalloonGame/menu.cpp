#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "menu.h"

using namespace sf;

Menu::Menu() {
	m_isActive = true;
	m_Texture = Texture();
}
void Menu::New(int x, int y) {
	m_Texture.loadFromFile("play button.png");
	Sprite Menu;
	Menu.setTexture(m_Texture);
	Menu.setPosition(Vector2f(x, y));
	m_Sprite = Menu;
}