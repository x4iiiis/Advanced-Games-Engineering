#include "object.h"

class weaponUpgrade : public object
{
public:
	bool spawned = false;
	bool activated = false;
	sf::Time timeLeft = sf::seconds(10);
	sf::Time duration = sf::seconds(10);

	sf::Clock activeClock;
	sf::Clock spawnClock;

	weaponUpgrade();
	void update();
};