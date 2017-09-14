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
	/*if (spawned == true && timeLeft > 0)
	{
		timeLeft--;
	}

	if (timeLeft <= 0)
	{
		spawned = false;
		timeLeft = 30;
		std::cout << "Resupply despawned!" << std::endl;
		std::cout << "" << std::endl;
	}


	///*/
	if (spawnClock.getElapsedTime() >= timeLeft && spawned == true)
	{
		spawned = false;
		spawnClock.restart();
		std::cout << "Resupply despawned!" << std::endl;
		std::cout << "" << std::endl;
	}

}