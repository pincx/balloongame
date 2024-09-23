#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "bloon.h"

using namespace sf;

Bloon::Bloon() {
	b_Health = 5;
	b_Speed = 0;
	b_isDead = false;
	b_Position = Vector2f(0, 0);
}

Sprite Bloon::spawn(int x, int y) {
	b_Texture.loadFromFile("balloon.png");

	Sprite b;
	b.setTexture(b_Texture);
	b.setPosition(Vector2f(x, y));
	return b;
}

// Checks if the mouse is colliding with a sprite upon click
// Parameters: Sprite s, RenderWindow w
/* 
Usage:
	if (Mouse::isButtonPressed(Mouse::Button::Left)) {
		CheckSpriteCollision(balloon, MainWindow); 
	}
*/
bool CheckSpriteCollision(Sprite s, RenderWindow& w) {
	if (Mouse::isButtonPressed(Mouse::Button::Left)) {
		Vector2i MousePosition = Mouse::getPosition(w);
		Vector2f SpritePosition = s.getPosition();
		Vector2f SpriteSize = s.getScale();

		if (MousePosition.x >= SpritePosition.x &&
			MousePosition.x <= (SpritePosition.x + s.getGlobalBounds().width) &&
			MousePosition.y >= SpritePosition.y &&
			MousePosition.y <= (SpritePosition.y + s.getGlobalBounds().height)) {
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}