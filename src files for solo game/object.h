#pragma once

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <functional>
#include <deque>
#include <list>
#include <vector>
using namespace std;

class object
{
public:
	//Hitbox
	sf::RectangleShape rect;
	//Sprite
	sf::Sprite sprite;
	//Text.. dunno what for yet lmao
	sf::Text text;
};