#include "enemy2.h"

enemy2::enemy2()
{
	rect.setSize(sf::Vector2f(64, 64));
	rect.setFillColor(sf::Color::Blue);
	rect.setPosition(75, 0);
}

void enemy2::update()
{
	sprite.setPosition(rect.getPosition());
}

void enemy2::movement()
{
	rect.move(0, movementSpeed);
}