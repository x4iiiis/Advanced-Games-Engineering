#include "object.h"

class healthRegen : public object
{
public:
	bool spawned = false;
	sf::Time timeLeft = sf::seconds(10);

	healthRegen();
	void update();
};