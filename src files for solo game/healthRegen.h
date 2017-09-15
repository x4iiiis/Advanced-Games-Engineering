#include "object.h"

class healthRegen : public object
{
public:
	bool spawned = false;
	sf::Time timeLeft = sf::seconds(10);
	sf::Clock spawnClock;

	healthRegen();
	void update();
};