#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "bloon.h"
#include "TextureHolder.h"
using namespace sf;
bool CheckSpriteCollision(Sprite s, RenderWindow& w) {
	if (Mouse::isButtonPressed(Mouse::Button::Left)) {
		Vector2i MousePosition = Mouse::getPosition(w);
		Vector2f SpritePosition = s.getPosition();

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
Bloon::Bloon() {
	b_Speed = 0;
	b_Scale = 0.1f;
	b_Position = Vector2f(0, 0);
	b_isDead = false;
	b_Texture = Texture();
}
Sprite Bloon::spawn(int x, int y) {
	// in the future, use this:
	// Bloon.setTexture(TextureHolder::GetTexture("balloon.png"));
	b_Texture.loadFromFile("balloon.png");
	Sprite Bloon;
	Bloon.setTexture(b_Texture);
	Bloon.setPosition(Vector2f(x, y));
	b_Health = RandomHealth(1, 3);
	Bloon.setScale(b_Scale, b_Scale);
	b_Sprite = Bloon;
	return Bloon;	
}
int Bloon::RandomHealth(int min, int max) {
	int f = rand() % max + min;
	return f;
}
void Bloon::hit() {
	b_Health -= 1;
	if (b_Health == 0) {
		b_isDead = true;
	}
}
bool Bloon::Random(int min, int max, int o) {
	int random = rand() % max + min;
	if (random == o) {
		return true;
	}
	else {
		return false;
	}
}
