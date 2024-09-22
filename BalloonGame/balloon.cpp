#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

// Creates a small balloon sprite, positioned onscreen with x, y, and scaled by s.
// Usage: Sprite balloon = createSmallBalloon(0, 0, 0.25f);
Sprite createSmallBalloon(int x, int y, int s) {
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
