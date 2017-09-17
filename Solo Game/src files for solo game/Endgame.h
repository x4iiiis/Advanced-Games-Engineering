#pragma once
#include "SFML/Graphics.hpp"

class Endgame
{
public:
	Endgame(float w, float h, int score);

	void draw(sf::RenderWindow &window);

private:
	sf::Font font;
	sf::Text endgame;
	sf::Text title;
	sf::Text title2;
	sf::Text yourScore;
	sf::Text highscore;
};