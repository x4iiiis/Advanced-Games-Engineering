#include "healthRegen.h"

healthRegen::healthRegen()
{
	//dunno if this will work okay but make a rocket sprite with 10x10 dimentions
	rect.setSize(sf::Vector2f(30, 30));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Yellow);
	sprite.setPosition(rect.getPosition());
}

void healthRegen::update()
{
	sprite.setPosition(rect.getPosition());

	if (spawned == true)
	{
		if (spawnClock.getElapsedTime() >= timeLeft)
		{
			spawnClock.restart();
			spawned = false;
			std::cout << "Health despawned!" << std::endl;
			std::cout << "" << std::endl;
		}
	}
}