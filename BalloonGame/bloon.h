#pragma once
#ifndef BLOON_H
#define BLOON_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

bool CheckSpriteCollision(sf::Sprite s, sf::RenderWindow& w);

class Bloon {
	private:
		int b_Health;
		int b_Speed;
		float b_Scale;
		bool b_isDead;
		sf::Sprite b_Sprite;
		sf::Vector2f b_Position;
		sf::Texture b_Texture;
	public:
		Bloon();
		sf::Sprite spawn(int x, int y);
		void hit();
		int getHealth();
		int getSpeed();
		bool isDead() const { return b_isDead; };
		sf::Sprite getSprite() const { return b_Sprite; }
};
#endif