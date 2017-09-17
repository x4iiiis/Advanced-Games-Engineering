#include "enemy1.h"

enemy1::enemy1()
{
	rect.setSize(sf::Vector2f(64, 64));
	rect.setFillColor(sf::Color::Blue);
	rect.setPosition(225, 0);
}

void enemy1::update()
{
	sprite.setPosition(rect.getPosition());
}

void enemy1::movement()
{
	rect.move(0, movementSpeed);
}