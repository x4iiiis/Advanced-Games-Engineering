#include "enemySlower.h"

enemySlower::enemySlower()
{
	//dunno if this will work okay but make a rocket sprite with 10x10 dimentions
	rect.setSize(sf::Vector2f(30, 30));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Yellow);
}

void enemySlower::update()
{
	if (spawned == true && timeLeft > sf::seconds(0))
	{
		timeLeft--;
	}

	if (timeLeft <= 0)
	{
		spawned = false;
		timeLeft = 30;
		std::cout << "Enemy slower despawned!" << std::endl;
		std::cout << "" << std::endl;
	}

	if (activated == true && duration > 0)
	{
		spawned = false;
		duration--;
		std::cout << "Enemy Slower activated" << std::endl;
		std::cout << "" << std::endl;
	}

	if (duration <= 0)
	{
		activated = false;
		std::cout << "Enemy Slower expired" << std::endl;
		std::cout << "" << std::endl;

	}
}