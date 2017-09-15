#include "resupply.h"

resupply::resupply()
{
	//dunno if this will work okay but make a rocket sprite with 10x10 dimentions
	rect.setSize(sf::Vector2f(30, 30));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Yellow);
}

void resupply::update()
{
<<<<<<< HEAD
	sprite.setPosition(rect.getPosition());
=======
	/*if (spawned == true && timeLeft > 0)
	{
		timeLeft--;
	}
>>>>>>> origin/master

	if (spawned == true)
	{
		if (spawnClock.getElapsedTime() >= timeLeft)
		{
			spawnClock.restart();
			spawned = false;
			std::cout << "Resupply despawned!" << std::endl;
			std::cout << "" << std::endl;
		}
	}

<<<<<<< HEAD
=======

	///*/
	if (spawnClock.getElapsedTime() >= timeLeft && spawned == true)
	{
		spawned = false;
		spawnClock.restart();
		std::cout << "Resupply despawned!" << std::endl;
		std::cout << "" << std::endl;
	}

>>>>>>> origin/master
}