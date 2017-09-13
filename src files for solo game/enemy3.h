#include "object.h"

class enemy3 : public object
{
public:
	int Health = 100;
	int WeaponStrength = 1;
	float movementSpeed = 0.015f;

	enemy3();
	void update();
	void movement();
};