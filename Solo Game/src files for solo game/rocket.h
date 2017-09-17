#include "object.h"

class rocket : public object
{
public:
	float speed = 0.5;
	int damage = 1;
	int range = 300;
	bool exploded = false;

	rocket();
	void update();
};

