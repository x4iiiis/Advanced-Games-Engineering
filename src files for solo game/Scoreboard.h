#pragma once
#include "SFML/Graphics.hpp"


class Scoreboard
{
public:
	Scoreboard(float w, float h);

	void draw(sf::RenderWindow &window);
	

private:
	sf::Font font;
	sf::Text highscore;
};