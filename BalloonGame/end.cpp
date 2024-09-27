#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "end.h"

using namespace sf;

EndScreen::EndScreen() {
	Texture pTexture;
	Texture gTexture;
	Texture qTexture;
}
// horrible
void EndScreen::New(int x, int y) {
	pTexture.loadFromFile("replay.png");
	gTexture.loadFromFile("win.png");
	qTexture.loadFromFile("quit.png");
	Sprite pSprite;
	Sprite gSprite;
	Sprite qSprite;
	pSprite.setTexture(pTexture);
	gSprite.setTexture(gTexture);
	qSprite.setTexture(qTexture);
	pSprite.setScale(0.625f, 0.625f);
	gSprite.setScale(0.625f, 0.625f);
	qSprite.setScale(0.625f, 0.625f);
	pSprite.setPosition(Vector2f(x, y + (gSprite.getGlobalBounds().height + 20)));
	qSprite.setPosition(Vector2f(x + (gSprite.getGlobalBounds().width + 20), y));
	gSprite.setPosition(Vector2f(x, y));

	ReplayGameButtonSprite = pSprite;
	CongratulationsSprite = gSprite;
	QuitGameSprite = qSprite;
}