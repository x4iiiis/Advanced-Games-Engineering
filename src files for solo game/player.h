#include "object.h"

class player : public object
{
public:
	int health = 100;
	int ammo = 25;
	int weaponStrength = 1;
	float movementSpeed = 0.5;

	player();
	void update();
};