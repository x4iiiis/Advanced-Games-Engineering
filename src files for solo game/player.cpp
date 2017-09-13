#include "player.h"

player::player()
{
	rect.setSize(sf::Vector2f(64, 64));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(125, 250);
}

void player::update()
{

	//Altered to allow for WASD movement as well as arrow keys
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
	{
		if (rect.getPosition().x > -40)
		{
			//rect.move.x--;
			//rect.setPosition(rect.getPosition().x -1, rect.getPosition().y);
			rect.move(-movementSpeed, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
	{
		if (rect.getPosition().x < 311)
		{
			//rect.move.x++;
			//rect.setPosition(rect.getPosition().x + 1, rect.getPosition().y);
			rect.move(movementSpeed, 0);
		}
	}

	//Adding up and down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
	{
		if (rect.getPosition().y < 306)
		{
			//rect.move.y++;
			//rect.setPosition(rect.getPosition().x, rect.getPosition().y +1);
			rect.move(0, movementSpeed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
	{
		if (rect.getPosition().y > -34)
		{
			//rect.move.y--;
			//rect.setPosition(rect.getPosition().x, rect.getPosition().y -1);
			rect.move(0, -movementSpeed);
		}
	}
	sprite.setPosition(rect.getPosition());
}