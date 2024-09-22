#pragma once

#ifndef BALLOON_H
#define BALLOON_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

sf::Sprite createSmallBalloon(int x, int y);
int CheckSpriteCollision(sf::Sprite s, sf::RenderWindow& w);

#endif