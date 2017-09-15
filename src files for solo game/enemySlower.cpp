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
<<<<<<< HEAD
	sprite.setPosition(rect.getPosition());

	if (spawnClock.getElapsedTime() >= timeLeft && spawned == true)
=======
	//if (spawned == true && spawnClock.getElapsedTime().asSeconds > timeLeft)//timeLeft > sf::seconds(0))
	//{
	//	timeLeft--;
	//}

	/*if (timeLeft <= 0)
>>>>>>> origin/master
	{
		spawned = false;
		std::cout << "Enemy slower despawned!" << std::endl;
		std::cout << "" << std::endl;
	}*/


	if (spawnClock.getElapsedTime() >= timeLeft && spawned == true)
	{
		spawned = false;
		spawnClock.restart();
		std::cout << "Enemy slower despawned!" << std::endl;
		std::cout << "" << std::endl;
	}



	if (activated == true && activeClock.getElapsedTime() <= duration) //duration > 0)
	{
		spawned = false;
<<<<<<< HEAD
=======
		activeClock.restart();
>>>>>>> origin/master
		std::cout << "Enemy Slower activated" << std::endl;
		std::cout << "" << std::endl;
	}

	if (activeClock.getElapsedTime() >= duration && activated == true)//(duration <= 0)
	{
		activated = false;
		spawnClock.restart();
		std::cout << "Enemy Slower expired" << std::endl;
		std::cout << "" << std::endl;

	}
}