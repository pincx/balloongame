#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

Sprite createSmallBalloon(int x, int y) {
	int Scale = 0.2;

    Texture texture;
    texture.loadFromFile("balloon.png");

    Sprite BalloonSprite(texture);

    BalloonSprite.setPosition(x, y);
    BalloonSprite.setScale(0.25f, 0.25f);

    return BalloonSprite;
}