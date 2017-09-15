#include "Endgame.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

Endgame::Endgame(float w, float h, int score)
{
	if (!font.loadFromFile("res/fonts/arial.ttf"))
	{
		//handle error
		std::cout << "arial font doesny work" << std::endl;
	}


	endgame.setFont(font);
	endgame.setFillColor(sf::Color::Red);
	endgame.setString("GAME OVER!");
	endgame.setCharacterSize(30);
	endgame.setPosition(sf::Vector2f(w / 2, (h / (5 + 1) * 1)));


	title.setFont(font);
	title.setFillColor(sf::Color::White);
	title.setString("Highscore:");
	title.setCharacterSize(16);
	title.setPosition(sf::Vector2f(w / 2, (h / (5 + 1) * 2)));

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
	highscore.setFillColor(sf::Color::White);
	highscore.setString(to_string(highScoar));
	highscore.setCharacterSize(14);
	highscore.setPosition(sf::Vector2f(w / 2, (h / (5 + 1) * 3)));


	title2.setFont(font);
	title2.setFillColor(sf::Color::White);
	title2.setString("Your score:");
	title2.setCharacterSize(16);
	title2.setPosition(sf::Vector2f(w / 2, (h / (5 + 1) * 4)));

	yourScore.setFont(font);
	yourScore.setFillColor(sf::Color::White);
	yourScore.setString(to_string(score));
	yourScore.setCharacterSize(14);
	yourScore.setPosition(sf::Vector2f(w / 2, (h / (5 + 1) * 5)));
}

void Endgame::draw(sf::RenderWindow &window)
{
	window.draw(endgame);
	window.draw(title);
	window.draw(highscore);
	window.draw(title2);
	window.draw(yourScore);
}
