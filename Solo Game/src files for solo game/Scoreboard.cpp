#include "Scoreboard.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

Scoreboard::Scoreboard(float w, float h)
{
	if (!font.loadFromFile("res/fonts/arial.ttf"))
	{
		//handle error
		std::cout << "arial font doesny work" << std::endl;
	}

	int highScoar;
	std::ifstream hiscores("res/Scoreboard.txt");
	if (hiscores.is_open())
	{
		hiscores >> highScoar;
	}
	else
	{
		highScoar = 0;
	}


	highscore.setFont(font);
	highscore.setFillColor(sf::Color::Green);
	highscore.setString(to_string(highScoar));
	highscore.setCharacterSize(24);
	highscore.setPosition(sf::Vector2f(w / 2, h / 2));
}

void Scoreboard::draw(sf::RenderWindow &window)
{
	window.draw(highscore);
}
