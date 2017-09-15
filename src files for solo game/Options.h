#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4

class Options
{
public:
	Options(float w, float h);

	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int getSelection();

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};