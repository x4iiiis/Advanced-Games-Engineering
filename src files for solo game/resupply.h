#include "object.h"

class resupply : public object
{
public:
	bool spawned = false;
	sf::Time timeLeft = sf::seconds(10);
	sf::Clock spawnClock;

	resupply();
	void update();
};
