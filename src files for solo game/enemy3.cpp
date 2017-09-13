#include "enemy3.h"

enemy3::enemy3()
{
	rect.setSize(sf::Vector2f(64, 64));
	rect.setFillColor(sf::Color::Blue);
	rect.setPosition(125, 0);
}

void enemy3::update()
{
	sprite.setPosition(rect.getPosition());
}

void enemy3::movement()
{
	rect.move(0, movementSpeed);
}