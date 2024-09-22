#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "mouse.h"

using namespace sf;

int CheckSpriteCollision(Sprite s, RenderWindow& w) {
	if (Mouse::isButtonPressed(Mouse::Button::Left)) {
		Vector2i MousePosition = Mouse::getPosition(w);
		Vector2f SpritePosition = s.getPosition();
		Vector2f SpriteSize = s.getScale();

		if (MousePosition.x >= SpritePosition.x &&
			MousePosition.x <= (SpritePosition.x + s.getGlobalBounds().width) &&
			MousePosition.y >= SpritePosition.y &&
			MousePosition.y <= (SpritePosition.y + s.getGlobalBounds().height)) {
			return 1;
		}
		else
		{
			return 0;
		}
	}
}