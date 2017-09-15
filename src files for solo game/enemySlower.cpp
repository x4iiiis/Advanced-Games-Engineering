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
	sprite.setPosition(rect.getPosition());

	if (spawnClock.getElapsedTime() >= timeLeft && spawned == true)
	{
		spawned = false;
		std::cout << "Enemy slower despawned!" << std::endl;
		std::cout << "" << std::endl;
	}



	if (activated == true && activeClock.getElapsedTime() <= duration) //duration > 0)
	{
		spawned = false;
		std::cout << "Enemy Slower activated" << std::endl;
		std::cout << "" << std::endl;
	}

	if (activeClock.getElapsedTime() >= duration && activated == true)//(duration <= 0)
	{
		activated = false;
		std::cout << "Enemy Slower expired" << std::endl;
		std::cout << "" << std::endl;

	}
}