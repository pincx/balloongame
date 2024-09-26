#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "end.h"

using namespace sf;

EndScreen::EndScreen() {
	Texture play_Texture;
	Texture gz_Texture;
	Texture quit_Texture;
}
void EndScreen::New(int x, int y) {
	play_Texture.loadFromFile("replay.png");
	m_Texture.loadFromFile("play button.png");
	Sprite Menu;
	Menu.setTexture(m_Texture);
	Menu.setPosition(Vector2f(x, y));
	m_Sprite = Menu;
}