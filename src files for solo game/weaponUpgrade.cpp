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
	if (spawned == true && timeLeft > 0)
	{
		timeLeft--;
	}

	if (timeLeft <= 0)
	{
		spawned = false;
		timeLeft = 30;
		std::cout << "Weapon Upgrade despawned!" << std::endl;
		std::cout << "" << std::endl;
	}

	if (activated == true && duration > 0)
	{
		spawned = false;
		duration--;
		std::cout << "Weapon Upgrade activated" << std::endl;
		std::cout << "" << std::endl;
	}

	if (duration <= 0)
	{
		activated = false;
		std::cout << "Weapon Upgrade expired" << std::endl;
		std::cout << "" << std::endl;

	}
}