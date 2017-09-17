#include "object.h"

class enemy2 : public object
{
public:
	int Health = 150;
	int WeaponStrength = 1;
	float movementSpeed = 0.015f;

	enemy2();
	void update();
	void movement();
};