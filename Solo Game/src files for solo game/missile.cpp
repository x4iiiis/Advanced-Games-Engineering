#include "missile.h"

missile::missile()
{
	//dunno if this will work okay but make a rocket sprite with 10x10 dimentions
	rect.setSize(sf::Vector2f(25, 25));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Red);
}

void missile::update()
{
	rect.move(0, -speed);
	sprite.setPosition(rect.getPosition());

	range--;

	if (range <= 0)
	{
		std::cout << "ran out of range" << std::endl;
		exploded = true;
	}
}