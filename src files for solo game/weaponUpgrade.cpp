#include "weaponUpgrade.h"

weaponUpgrade::weaponUpgrade()
{
	//dunno if this will work okay but make a rocket sprite with 10x10 dimentions
	rect.setSize(sf::Vector2f(30, 30));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Yellow);
}

void weaponUpgrade::update()
{
<<<<<<< HEAD
	sprite.setPosition(rect.getPosition());

	if (spawnClock.getElapsedTime() >= timeLeft && spawned == true)
	{
		spawned = false;
=======
	if (spawnClock.getElapsedTime() >= timeLeft && spawned == true)
	{
		spawned = false;
		spawnClock.restart();
>>>>>>> origin/master
		std::cout << "Weapon Upgrade despawned!" << std::endl;
		std::cout << "" << std::endl;
	}

	if (activated == true && activeClock.getElapsedTime() >= duration) //duration > 0)
	{
		spawned = false;
<<<<<<< HEAD
=======
		activeClock.restart();
>>>>>>> origin/master
		std::cout << "Weapon Upgrade activated" << std::endl;
		std::cout << "" << std::endl;
	}

	if (activeClock.getElapsedTime() >= duration && activated == true)//(duration <= 0)
	{
		activated = false;
		spawnClock.restart();
		std::cout << "Weapon Upgrade expired" << std::endl;
		std::cout << "" << std::endl;

	}

}