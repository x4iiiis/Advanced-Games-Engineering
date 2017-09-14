#include "object.h"

class enemySlower : public object
{
public:
	bool spawned = false;
	bool activated = false;
	sf::Time timeLeft = sf::seconds(10);
	sf::Time duration = sf::seconds(10);

	enemySlower();
	void update();
};