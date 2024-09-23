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
		bool b_isDead;

		Vector2f b_Position;
		Texture b_Texture;

	public:
		Sprite spawn();
		void kill();
		int getHealth();
		Sprite spawn(int x, int y);
};

#endif
