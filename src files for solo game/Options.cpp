#include "Options.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Options::Options(float w, float h)
{
	if (!font.loadFromFile("res/fonts/arial.ttf"))
	{
		//handle error
		std::cout << "arial font doesny work" << std::endl;
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Blue);
	menu[0].setString("Difficulty:");
	menu[0].setPosition(sf::Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("1");
	menu[1].setPosition(sf::Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("2");
	menu[2].setPosition(sf::Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("3");
	menu[3].setPosition(sf::Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	selectedItemIndex = 0;
}


void Options::moveUp()
{

	if (selectedItemIndex - 1 >= 1)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
}

void Options::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
}

int Options::getSelection()
{
	return selectedItemIndex;
}

void Options::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}