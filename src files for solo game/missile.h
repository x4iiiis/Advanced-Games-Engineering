#include "object.h"

class missile : public object
{
public:
	float speed = 0.5;
	int damage = 1;
	int range = 300;
	bool exploded = false;

	missile();
	void update();
};

