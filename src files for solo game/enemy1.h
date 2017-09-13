#include "object.h"

class enemy1 : public object
{
public:
	int Health = 200;
	int WeaponStrength = 1;
	float movementSpeed = 0.015f;

	enemy1();
	void update();
	void movement();
};