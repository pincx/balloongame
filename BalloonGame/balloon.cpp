#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

// Creates a small balloon sprite, positioned onscreen with x, y.
// Usage: Sprite balloon = createSmallBalloon(0, 0);
Sprite createSmallBalloon(int x, int y) {
    Texture texture;
    texture.loadFromFile("balloon.png");

    Sprite BalloonSprite(texture);

    BalloonSprite.setPosition(x, y);
    BalloonSprite.setScale(0.25f, 0.25f);

    return BalloonSprite;
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
}
