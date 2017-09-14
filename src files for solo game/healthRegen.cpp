#include "healthRegen.h"

healthRegen::healthRegen()
{
	//dunno if this will work okay but make a rocket sprite with 10x10 dimentions
	rect.setSize(sf::Vector2f(30, 30));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Yellow);
}

void healthRegen::update()
{
	if (spawned == true && timeLeft > 0)
	{
		timeLeft--;
	}

	if (timeLeft <= 0)
	{
		spawned = false;
		timeLeft = 30;
		std::cout << "Health Regen despawned!" << std::endl;
		std::cout << "" << std::endl;
	}
}