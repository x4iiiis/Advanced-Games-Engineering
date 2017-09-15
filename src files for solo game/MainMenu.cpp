#include "MainMenu.h"
#include <stdio.h>
#include <iostream>

using namespace std;

MainMenu::MainMenu(float w, float h)
{
	if (!font.loadFromFile("res/fonts/arial.ttf"))
	{
		//handle error
		std::cout << "arial font doesny work" << std::endl;	
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Green);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Scoreboard");
	menu[1].setPosition(sf::Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Options");
	menu[2].setPosition(sf::Vector2f(w / 2, h / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}


void MainMenu::moveUp()
{

	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
}

void MainMenu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
}

int MainMenu::getSelection()
{
	return selectedItemIndex;
}

void MainMenu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}