#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <fstream>
#include <SFML/Audio.hpp>

#include "MainMenu.h"
#include "Scoreboard.h"
#include "Endgame.h"
#include "Options.h"

#include "player.h"
#include "object.h"
#include "rocket.h"
#include "missile.h"
#include "enemy1.h"
#include "enemy2.h"
#include "enemy3.h"
#include "healthRegen.h"
#include "resupply.h"
#include "weaponUpgrade.h"
#include "enemySlower.h"



using namespace sf;

//Sprites
//Sprite player;
//Sprite enemy1;
//Sprite enemy2;
//Sprite enemy3;
//Do we need to use sprites for the powerups too? Probably...
//Sprite HealthRegen;
//Sprite Resupply;
//Sprite DecreasedEnemySpeed;
//Sprite WeaponUpgrade;


//Textures
Texture playerTex;
Texture enemy1Tex;
Texture enemy2Tex;
Texture enemy3Tex;
Texture rocketTex;
Texture missileTex;
//If we do need sprites for powerups they'll need textures too.. well actually either way they will I think
Texture HealthRegenTex;
Texture ResupplyTex;
Texture enemySlowerTex;
Texture WeaponUpgradeTex;


//Player Name
String playerName;		//When the game starts take in the player's name for the scoreboard, reset it at gameover() AFTER it's been saved to the scoreboard

//Difficulty (1 - 3)
int Difficulty = 1; 

//Scores
int Score = 0;
int HighScore = 0;


//ifstream InputFile("res/Scoreboard.txt");
//if(InputFile.isOpen())
//{
//	HighScore >> 
//}



//Game States
bool Welcome = true;
bool Board = false;
bool optionScreen = false;
bool InPlay = false;
bool Paused = false;
bool GameOver = false;

//Powerups				//Have a counter for the time that decreased enemy speed is on for, make it last like 10 seconds or so
bool gotHealthRegen = false;
bool gotResupply = false;
bool gotDecreasedEnemySpeed = false;
bool gotWeaponUpgrade = false;


//Fonts			tbh there's probably only gonna be one or two fonts that get recycled throughout, fuck downloading loads of the bastards
Font TitleFont;
Font ButtonFont;
Font ScoreFont;

//Texts
Text TitleText;
Text HowToPlayText;
Text PlayText;
Text PauseText;
Text HighScoreText;

//Buttons??


sf::SoundBuffer sfxBuffer;

bool aPowerupIsSpawned = false;




void WelcomeMethod()
{
	std::cout << "Hello world! Welcome to [insert game title here]!" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Controls:" << std::endl;
	std::cout << "WASD or the arrow keys to move" << std::endl;
	std::cout << "SPACE to shoot" << std::endl;
	std::cout << "P to pause" << std::endl;
	std::cout << "ESCAPE to quit" << std::endl;
	std::cout << "" << std::endl;

	ifstream InputFile("res/Scoreboard.txt");
	if (InputFile.is_open())
	{
		InputFile >> HighScore;
	}
	else
	{
		ofstream OutputFile("res/Scoreboard.txt");
		HighScore = 0;
		OutputFile << HighScore;

	}




}

void Pause()
{
	if (Paused == false)
	{
		Paused = true;

		std::cout << "Game paused..." << std::endl;
		std::cout << "Press P to resume" << std::endl;
		std::cout << "" << std::endl;
	}
	else 
	{
		Paused = false;
		
		std::cout << "Game resumed" << std::endl;
		std::cout << "" << std::endl;
	}
}

void GameOverMethod()
{
	GameOver = true;
	InPlay = false;
	std::cout << "GAME OVER!" << std::endl;
	std::cout << "" << std::endl;

	ifstream InputFile("res/Scoreboard.txt");
	if(InputFile.is_open())
	{
		InputFile >> HighScore;
		std::cout << "Highscore from the file is: " << HighScore << std::endl;
		std::cout << "" << std::endl;

		//If current score is greater than the highest recorded score, record the current score as the high score
		if (Score > HighScore)
		{
			std::cout << "New high score!" << std::endl;
			std::cout << "" << std::endl;
			HighScore = Score;
			//Do stuff with high score, writing to a file etc
			ofstream OutputFile("res/Scoreboard.txt");
			OutputFile << HighScore;
			//OutputFile << Score;
		}
	}

	
	std::cout << "High Score: " << HighScore << std::endl;
	std::cout << "Score :" << Score << std::endl;
	std::cout << "" << std::endl;

	//Resetting the current score, probably won't need this here but for now I do cause the game doesn't actually end
	Score = 0;
}

//void ModeCheck()
//{
//	if (Welcome == true)
//	{
//		//Main Menu
//		MainMenu();
//	}
//
//	if (InPlay == true)
//	{
//		//Play
//	}
//
//	if (Paused == true)
//	{
//		//Pause
//	}
//
//	if (GameOver == true)
//	{
//		//Gameover
//	}
//}

void Load() 
{
	if (!playerTex.loadFromFile("res/img/player.png")) 
	{
		throw std::invalid_argument("Loading error!");
	}


	//Enemy Textures
	if (!enemy1Tex.loadFromFile("res/img/enemy1.png"))
	{
		throw std::invalid_argument("enemy1 texture's fucked!");
	}
	
	if (!enemy2Tex.loadFromFile("res/img/enemy2.png"))
	{
		throw std::invalid_argument("enemy2 texture's fucked!");
	}
	
	if (!enemy3Tex.loadFromFile("res/img/enemy3.png"))
	{
		throw std::invalid_argument("enemy3 texture's fucked!");
	}

	if (!rocketTex.loadFromFile("res/img/rocket.png"))
	{
		throw std::invalid_argument("rocket texture's fucked!");
	}

	if (!missileTex.loadFromFile("res/img/missile.png"))
	{
		throw std::invalid_argument("missile texture's fucked!");
	}

	//sound buffer 
	if (!sfxBuffer.loadFromFile("res/sfx/pop.wav"))
	{
		throw std::invalid_argument("Pop sound's fucked!");
	}


	

	if (!HealthRegenTex.loadFromFile("res/img/red.png"))
	{
		throw std::invalid_argument("Health Regen textures's fucked!");
	}

	if (!ResupplyTex.loadFromFile("res/img/yellow.png"))
	{
		throw std::invalid_argument("Resupply texture's fucked!");
	}

	if (!enemySlowerTex.loadFromFile("res/img/blue.png"))
	{
		throw std::invalid_argument("Enemy Slower texture's fucked!");
	}

	if (!WeaponUpgradeTex.loadFromFile("res/img/green.png"))
	{
		throw std::invalid_argument("Weapon Upgrade texture's fucked!");
	}
	////Loading the welcome font
	//if (!welcomeFont.loadFromFile("res/fonts/orangejuice/orangejuice2.tff"))
	//{
	//	throw std::invalid_argument("fuuuuuuuuuck!");
	//}

	//welcomeText.setFont(welcomeFont);
	//welcomeText.setString("Welcome!");
	//welcomeText.setCharacterSize(24);
	//welcomeText.setFillColor(sf::Color::Red);
	//welcomeText.setStyle(sf::Text::Bold | sf::Text::Underlined);


	WelcomeMethod();

}



int main() 
{
	//tutorial
	//variables
	int counter;
	int counter2;
	int counter3;
	float enemySpawnRate;



	//trying to make the spawn rate for enemies
	static sf::Clock spawnClock;
	
	//timer for how often rockets can be fired
	static sf::Clock shotClock;

	//timer for score increase for survival
	static sf::Clock scoreClock;

	//Powerup clock
	static sf::Clock powerupClock;



	//Pop sound setup
	sf::Sound pop;
	pop.setBuffer(sfxBuffer);

	

	

	RenderWindow window(VideoMode(400, 400), "SFML works!", sf::Style::Resize);

	//Main Menu
	MainMenu menu(window.getSize().x, window.getSize().y);

	//Options
	Options difficultySelector(window.getSize().x, window.getSize().y);

	//Scoreboard
	Scoreboard scoreboard(window.getSize().x, window.getSize().y);

	//Gameover
	Endgame endgame(window.getSize().x, window.getSize().y, Score);




	//set frame limit to 60 (tutorial)
	window.setFramerateLimit(60);

	try 
	{
		Load();
	}
	catch (const std::exception &) 
	{
		std::cerr << "Load error" << std::endl;
		return 1;
	}






	//Creating the player the tutorial's way (c++ sfml 2.3.1 game design lesson 6)
	class player Player;
	Player.sprite.setTexture(playerTex);


	//Friendly Rocket Vector Array
	vector<rocket>::const_iterator rocketIterator;
	vector<rocket> rocketArray;

	//friendly rocket object
	class rocket rocket1;
	rocket1.sprite.setTexture(rocketTex);

	
	//Enemy Missile Vector Array
	vector<missile>::const_iterator missileIterator;
	vector<missile> missileArray;

	//Enemy Missile object
	class missile missile1;
	missile1.sprite.setTexture(missileTex);

	//Creating powerup objects
	class healthRegen healthRegen1;
	class resupply resupply1;
	class weaponUpgrade weaponUpgrade1;
	class enemySlower enemySlower1;
	healthRegen1.sprite.setTexture(HealthRegenTex);
	resupply1.sprite.setTexture(ResupplyTex);
	weaponUpgrade1.sprite.setTexture(WeaponUpgradeTex);
	enemySlower1.sprite.setTexture(enemySlowerTex);


	//Powerup Arrays
	vector<healthRegen>::const_iterator healthRegenIterator;
	vector<healthRegen> healthRegenArray;
	vector<resupply>::const_iterator resupplyIterator;
	vector<resupply> resupplyArray;
	vector<weaponUpgrade>::const_iterator weaponUpgradeIterator;
	vector<weaponUpgrade> weaponUpgradeArray;
	vector<enemySlower>::const_iterator enemySlowerIterator;
	vector<enemySlower> enemySlowerArray;





	//Enemy1 Vector Array
	vector<enemy1>::const_iterator enemy1Iterator;
	vector<enemy1> enemy1Array;

	//Enemy2 Vector Array
	vector<enemy2>::const_iterator enemy2Iterator;
	vector<enemy2> enemy2Array;

	//Enemy3 Vector Array
	vector<enemy3>::const_iterator enemy3Iterator;
	vector<enemy3> enemy3Array;


	//enemy objects
	class enemy1 enemy1;
	enemy1.sprite.setTexture(enemy1Tex);		//now haud oan cause I need multiple enemy types so I'm gonna need to sort a random thing here
												//actually maybe not hold on...
	class enemy2 enemy2;
	enemy2.sprite.setTexture(enemy2Tex);
	class enemy3 enemy3;
	enemy3.sprite.setTexture(enemy3Tex);

	//Enemies spawn at varying rates depending on the difficulty 
	switch (Difficulty)
	{
	case 1:
		//Enemies spawn every 7 seconds
		enemySpawnRate = 7.0f;
		break;
	case 2:
		//enemies spawn every 5 seconds
		enemySpawnRate = 5.0f;
		break;
	case 3:
		//enemies spawn every 3 seconds
		enemySpawnRate = 3.0f;
		break;
	default:
		break;
	}

	//Game loop
	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape)) 
		{
			window.close();
		}


		//Main Menu
		if (Welcome == true)
		{
			window.clear();
			
			if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
			{
				sleep(sf::seconds(0.1f));
				menu.moveUp();
			}
			if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
			{
				sleep(sf::seconds(0.1f));
				menu.moveDown();
			}
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				sleep(sf::seconds(0.1f));
				switch (menu.getSelection())
				{
				case 0:
					std::cout << "Play button pressed" << std::endl;
					powerupClock.restart();
					spawnClock.restart();
					window.clear();
					Welcome = false;
					InPlay = true;
					break;
				case 1: 
					std::cout << "Scoreboard button pressed" << std::endl;
					window.clear();
					Welcome = false;
					Board = true;
					break;
				case 2:
					std::cout << "Options pressed" << std::endl;
					window.clear();
					Welcome = false;
					optionScreen = true;
					break;
				default:
					break;
				}
			}

			window.clear();

			if (Welcome == true)
			{
				menu.draw(window);
				window.display();
			}
		}

		//Scoreboard
		if (Board == true)
		{
			Welcome = false;
			InPlay = false;
			window.clear();
			scoreboard.draw(window);
			window.display();
		}


		//Options
		if (optionScreen == true)
		{
			Welcome = false;
			InPlay = false;
			window.clear();
			difficultySelector.draw(window);
			window.display();

			if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
			{
				sleep(sf::seconds(0.1f));
				difficultySelector.moveUp();
			}
			if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
			{
				sleep(sf::seconds(0.1f));
				difficultySelector.moveDown();
			}
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				sleep(sf::seconds(0.1f));
				switch (difficultySelector.getSelection())
				{
				case 1:
					Difficulty = 1;
					std::cout << "Difficulty set to: " << Difficulty << std::endl;
					std::cout << "" << std::endl;
					optionScreen = false;
					Welcome = true;
					window.clear();
					break;
				case 2:
					Difficulty = 2;
					std::cout << "Difficulty set to: " << Difficulty << std::endl;
					std::cout << "" << std::endl;
					optionScreen = false;
					Welcome = true;
					window.clear();
					break;
				case 3:
					Difficulty = 3;
					std::cout << "Difficulty set to: " << Difficulty << std::endl;
					std::cout << "" << std::endl;
					optionScreen = false;
					Welcome = true;
					window.clear();
					break;
				default:
					break;
				}
			}
		}


		//Gameover
		if (GameOver == true)
		{
			window.clear();
			endgame.draw(window);
			window.display();
		}

		//Game is InPlay
		if (InPlay == true)
		{

			//Pausing and resuming the game
			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				//This function was being a pain in the ass, calling Pause() a million times as if I was constantly pressing P
				//The sleep function solves this problem
				sleep(sf::seconds(0.1f));
				Pause();

				if (Paused == true)
				{
					sf::Font pauseFont;

					if (!pauseFont.loadFromFile("res/fonts/arial.ttf"))
					{
						//handle error
						std::cout << "pause font doesny work" << std::endl;
					}

					PauseText.setFont(pauseFont);
					PauseText.setString("PAUSED");
					PauseText.setCharacterSize(24);
					PauseText.setColor(sf::Color::Blue);
					PauseText.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

					window.draw(PauseText);
					window.display();
				}
				

				

				//Wanted to be able to pause the survival timer but it looks like I'm gonna have to settle for just resetting it when you pause.. which kinda sucks
				scoreClock.restart();
				powerupClock.restart();

			}






			//This is what actually pauses the game
			//Everything that happens in game is within this if
			if (Paused == false)
			{
				window.clear();






				//Add 5 tp the score for every 10 seconds that the player survives
				if (scoreClock.getElapsedTime().asSeconds() >= 10.0f)
				{
					scoreClock.restart();
					std::cout << "survived 10 seconds" << std::endl;
					Score += 5;
					std::cout << "Score: " << Score << std::endl;
					std::cout << "" << std::endl;

				}


				if (healthRegenArray.empty() == true && resupplyArray.empty() == true && weaponUpgradeArray.empty() == true && enemySlowerArray.empty() == true)
				{
					aPowerupIsSpawned = false;
				}
				else
				{
					aPowerupIsSpawned = true;
				}

				//Powerups
				//randomly spawn one every 30 seconds, reset the clock every time one is picked up 
				if (powerupClock.getElapsedTime().asSeconds() >= 10 && aPowerupIsSpawned == false)
				{
					//sleep(sf::seconds(0.1)); /////////////////////////////////////////////////////////////////////// Just testing this 
					//randomly select a powerup
					int powerupSelector = ((rand() % 4) + 1);

					switch (powerupSelector)
					{
					case 1:
						//spawn Health
						healthRegen1.spawned = true;
						healthRegen1.spawnClock.restart();
						//healthRegen1.update();
						healthRegenArray.push_back(healthRegen1);
						healthRegen1.update();
						std::cout << "Health Spawned!" << std::endl;
						std::cout << "" << std::endl;
						break;
					case 2:
						//Spawn ammo
						resupply1.spawned = true;
						resupply1.spawnClock.restart();
						resupplyArray.push_back(resupply1);
						std::cout << "Resupply Spawned!" << std::endl;
						std::cout << "" << std::endl;
						break;
					case 3:
						//spawn weapon upgrade
						weaponUpgrade1.spawned = true;
						weaponUpgrade1.spawnClock.restart();
						weaponUpgrade1.activeClock.restart();
						weaponUpgradeArray.push_back(weaponUpgrade1);
						std::cout << "Weapon Upgrade Spawned!" << std::endl;
						std::cout << "" << std::endl;
						break;
					case 4:
						//spawn enemy slower
						enemySlower1.spawned = true;
						enemySlower1.spawnClock.restart();
						enemySlower1.activeClock.restart();
						enemySlowerArray.push_back(enemySlower1);
						std::cout << "Enemy Slower Spawned!" << std::endl;
						std::cout << "" << std::endl;
						break;
					default:
						break;
					}
					powerupClock.restart();
				}



				//Draw powerups
				counter = 0;
				for (healthRegenIterator = healthRegenArray.begin(); healthRegenIterator != healthRegenArray.end(); healthRegenIterator++)
				{
					healthRegenArray[counter].update();

					if (healthRegenArray[counter].spawned == true)
					{
						window.draw(healthRegenArray[counter].sprite);
					}
					else
					{
						healthRegenArray.erase(healthRegenIterator);
					}


					if (healthRegenArray.empty() == true)
					{
						break;
					}

					counter++;
				}
				counter = 0;
				for (resupplyIterator = resupplyArray.begin(); resupplyIterator != resupplyArray.end(); resupplyIterator++)
				{
					resupplyArray[counter].update();

					if (resupplyArray[counter].spawned == true)
					{
						window.draw(resupplyArray[counter].sprite);
					}
					else
					{
						resupplyArray.erase(resupplyIterator);
					}

					if (resupplyArray.empty() == true)
					{
						break;
					}

					counter++;
				}
				counter = 0;
				for (weaponUpgradeIterator = weaponUpgradeArray.begin(); weaponUpgradeIterator != weaponUpgradeArray.end(); weaponUpgradeIterator++)
				{
					weaponUpgradeArray[counter].update();

					if (weaponUpgradeArray[counter].spawned == true)
					{
						window.draw(weaponUpgradeArray[counter].sprite);
					}
					else
					{
						weaponUpgradeArray.erase(weaponUpgradeIterator);
					}

					if (weaponUpgradeArray.empty() == true)
					{
						break;
					}

					counter++;
				}
				counter = 0;
				for (enemySlowerIterator = enemySlowerArray.begin(); enemySlowerIterator != enemySlowerArray.end(); enemySlowerIterator++)
				{
					enemySlowerArray[counter].update();

					if (enemySlowerArray[counter].spawned == true)
					{
						window.draw(enemySlowerArray[counter].sprite);
					}
					else
					{
						enemySlowerArray.erase(enemySlowerIterator);
					}

					if (enemySlowerArray.empty() == true)
					{
						break;
					}

					counter++;
				}



				//Collision detection ------ player --> powerup
				if (Player.rect.getGlobalBounds().intersects(healthRegen1.rect.getGlobalBounds()) && healthRegenArray.empty() == false)
				{
					Player.health = Player.fullHealth;
					healthRegen1.update();
					std::cout << "hit health regen" << std::endl;
					std::cout << "" << std::endl;
					
					while (healthRegenArray.empty() == false)
					{
						healthRegenArray.erase(healthRegenArray.begin());
					}
				}

				
				if (Player.rect.getGlobalBounds().intersects(resupply1.rect.getGlobalBounds()) && resupplyArray.empty() == false)
				{
					Player.ammo += 25;
					resupply1.update();
					std::cout << "hit resupply" << std::endl;
					std::cout << "" << std::endl;

					while (resupplyArray.empty() == false)
					{
						resupplyArray.erase(resupplyArray.begin());
					}
				}
				if (Player.rect.getGlobalBounds().intersects(weaponUpgrade1.rect.getGlobalBounds()) && weaponUpgradeArray.empty() == false)
				{
					rocket1.damage *= 2;
					weaponUpgrade1.spawnClock.restart();
					weaponUpgrade1.activeClock.restart();
					weaponUpgrade1.activated = true;
					weaponUpgrade1.update();
					std::cout << "hit weapon upgrade" << std::endl;
					std::cout << "" << std::endl;

					while (weaponUpgradeArray.empty() == false)
					{
						weaponUpgradeArray.erase(weaponUpgradeArray.begin());
					}
				}
				if (Player.rect.getGlobalBounds().intersects(enemySlower1.rect.getGlobalBounds()) && enemySlowerArray.empty() == false)
				{
					enemySlower1.activated = true;
					enemySlower1.update();
					//enemy arrays movement speed decrease
					counter = 0;
					for (enemy1Iterator = enemy1Array.begin(); enemy1Iterator != enemy1Array.end(); enemy1Iterator++)
					{
						enemy1Array[counter].movementSpeed /= 2;
						counter++;
					}
					counter = 0;
					for (enemy2Iterator = enemy2Array.begin(); enemy2Iterator != enemy2Array.end(); enemy2Iterator++)
					{
						enemy2Array[counter].movementSpeed /= 2;
						counter++;
					}
					counter = 0;
					for (enemy3Iterator = enemy3Array.begin(); enemy3Iterator != enemy3Array.end(); enemy3Iterator++)
					{
						enemy3Array[counter].movementSpeed /= 2;
						counter++;
					}


					std::cout << "hit enemy slower" << std::endl;
					std::cout << "" << std::endl;


					while (enemySlowerArray.empty() == false)
					{
						enemySlowerArray.erase(enemySlowerArray.begin());
					}
				}








				//Collision detection ------ enemy -> player
				counter = 0;
				for (enemy1Iterator = enemy1Array.begin(); enemy1Iterator != enemy1Array.end(); enemy1Iterator++)
				{
					if (Player.rect.getGlobalBounds().intersects(enemy1Array[counter].rect.getGlobalBounds()))
					{
						std::cout << "enemy1 kamikazed player" << std::endl;
						std::cout << "" << std::endl;
						GameOverMethod();
					}
					counter++;
				}
				counter = 0;
				for (enemy2Iterator = enemy2Array.begin(); enemy2Iterator != enemy2Array.end(); enemy2Iterator++)
				{
					if (Player.rect.getGlobalBounds().intersects(enemy2Array[counter].rect.getGlobalBounds()))
					{
						std::cout << "enemy2 kamikazed player" << std::endl;
						std::cout << "" << std::endl;
						GameOverMethod();
					}
					counter++;
				}
				counter = 0;
				for (enemy3Iterator = enemy3Array.begin(); enemy3Iterator != enemy3Array.end(); enemy3Iterator++)
				{
					if (Player.rect.getGlobalBounds().intersects(enemy3Array[counter].rect.getGlobalBounds()))
					{
						std::cout << "enemy3 kamikazed player" << std::endl;
						std::cout << "" << std::endl;
						GameOverMethod();
					}
					counter++;
				}





				//Collision detection ------ rocket -> enemy
				counter = 0;
				for (rocketIterator = rocketArray.begin(); rocketIterator != rocketArray.end(); rocketIterator++)
				{
					counter2 = 0;
					for (enemy1Iterator = enemy1Array.begin(); enemy1Iterator != enemy1Array.end(); enemy1Iterator++)
					{
						if (rocketArray[counter].rect.getGlobalBounds().intersects(enemy1Array[counter2].rect.getGlobalBounds()))
						{
							std::cout << "enemy1 took a rocket to the face" << std::endl;
							std::cout << "" << std::endl;
							rocketArray[counter].exploded = true;
							enemy1Array[counter2].Health = enemy1Array[counter2].Health - ((100 / Difficulty) + 1);
						}

						counter2++;
					}
					counter2 = 0;
					for (enemy2Iterator = enemy2Array.begin(); enemy2Iterator != enemy2Array.end(); enemy2Iterator++)
					{
						if (rocketArray[counter].rect.getGlobalBounds().intersects(enemy2Array[counter2].rect.getGlobalBounds()))
						{
							std::cout << "enemy2 took a rocket to the face" << std::endl;
							std::cout << "" << std::endl;
							rocketArray[counter].exploded = true;
							enemy2Array[counter2].Health = enemy2Array[counter2].Health - ((100 / Difficulty) + 1);
						}

						counter2++;
					}
					counter2 = 0;
					for (enemy3Iterator = enemy3Array.begin(); enemy3Iterator != enemy3Array.end(); enemy3Iterator++)
					{
						if (rocketArray[counter].rect.getGlobalBounds().intersects(enemy3Array[counter2].rect.getGlobalBounds()))
						{
							std::cout << "enemy3 took a rocket to the face" << std::endl;
							std::cout << "" << std::endl;
							rocketArray[counter].exploded = true;
							enemy3Array[counter2].Health = enemy3Array[counter2].Health - ((100 / Difficulty) + 1);
						}

						counter2++;
					}

					counter++;
				}


				//Delete rockets on collision or after they run out of range 
				counter = 0;
				for (rocketIterator = rocketArray.begin(); rocketIterator != rocketArray.end(); rocketIterator++)
				{
					if (rocketArray[counter].exploded == true)
					{
						std::cout << "rocket exploded" << std::endl;
						std::cout << "" << std::endl;
						rocketArray.erase(rocketIterator);
						break;
					}
					counter++;
				}


				//Delete dead enemies
				counter = 0;
				for (enemy1Iterator = enemy1Array.begin(); enemy1Iterator != enemy1Array.end(); enemy1Iterator++)
				{
					if (enemy1Array[counter].Health < 1)
					{
						enemy1Array.erase(enemy1Iterator);
						pop.play();
						Score += 3;
						std::cout << "Score: " << Score << std::endl;
						std::cout << "" << std::endl;
						break;
					}
					counter++;
				}
				counter = 0;
				for (enemy2Iterator = enemy2Array.begin(); enemy2Iterator != enemy2Array.end(); enemy2Iterator++)
				{
					if (enemy2Array[counter].Health < 1)
					{
						enemy2Array.erase(enemy2Iterator);
						pop.play();
						Score += 2;
						std::cout << "Score: " << Score << std::endl;
						std::cout << "" << std::endl;
						break;
					}
					counter++;
				}
				counter = 0;
				for (enemy3Iterator = enemy3Array.begin(); enemy3Iterator != enemy3Array.end(); enemy3Iterator++)
				{
					if (enemy3Array[counter].Health < 1)
					{
						enemy3Array.erase(enemy3Iterator);
						pop.play();
						Score += 1;
						std::cout << "Score: " << Score << std::endl;
						std::cout << "" << std::endl;
						break;
					}
					counter++;
				}



				//Used for spawning enemies every 3/5/7 seconds depending on difficulty setting
				if (spawnClock.getElapsedTime().asSeconds() > enemySpawnRate)
				{
					spawnClock.restart();
					std::cout << enemySpawnRate << " seconds have passed" << std::endl;
					std::cout << "" << std::endl;

					//spawn a random enemy -- max 3 of each type
					int enemyType = ((rand() % 3) + 1);

					switch (enemyType)
					{
					case 1:
						if (enemy1Array.size() < 3)
						{
							std::cout << enemyType << " should be 1" << std::endl;
							std::cout << "" << std::endl;
							enemy1Array.push_back(enemy1);
						}
						break;
					case 2:
						if (enemy2Array.size() < 3)
						{
							std::cout << enemyType << " should be 2" << std::endl;
							std::cout << "" << std::endl;
							enemy2Array.push_back(enemy2);
						}
						break;
					case 3:
						if (enemy3Array.size() < 3)
						{
							std::cout << enemyType << " should be 3" << std::endl;
							std::cout << "" << std::endl;
							enemy3Array.push_back(enemy3);
						}
						break;
					default:
						break;
					}
				}

				//tutorial way of firing rockets ----- player needs to have ammo also
				if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					if (shotClock.getElapsedTime().asSeconds() >= 0.5f)
					{
						shotClock.restart();

						if (Player.ammo > 0)
						{
							//set rockets to fire from the middle of the sprite on X axis
							rocket1.rect.setPosition(Player.rect.getPosition().x + Player.rect.getSize().x / 2 - rocket1.rect.getSize().x / 2, Player.rect.getPosition().y);
							//Add rocket to array
							rocketArray.push_back(rocket1);
							//Reduce player's ammunition
							Player.ammo--;

							std::cout << "Ammunition: " << Player.ammo << std::endl;
							std::cout << "" << std::endl;
						}
						else
						{
							std::cout << "Out of ammo!" << std::endl;
							std::cout << "" << std::endl;
						}
					}
				}


				//Draw rockets
				counter = 0;

				for (rocketIterator = rocketArray.begin(); rocketIterator != rocketArray.end(); rocketIterator++)
				{
					rocketArray[counter].update();
					window.draw(rocketArray[counter].sprite);

					counter++;
				}


				//Draw enemies (gonna get messy cause there's gonna be 3 fucking loops)
				counter = 0;
				for (enemy1Iterator = enemy1Array.begin(); enemy1Iterator != enemy1Array.end(); enemy1Iterator++)
				{
					enemy1Array[counter].update();
					enemy1Array[counter].movement();
					window.draw(enemy1Array[counter].sprite);

					counter++;
				}
				counter = 0;
				for (enemy2Iterator = enemy2Array.begin(); enemy2Iterator != enemy2Array.end(); enemy2Iterator++)
				{
					enemy2Array[counter].update();
					enemy2Array[counter].movement();
					window.draw(enemy2Array[counter].sprite);

					counter++;
				}
				counter = 0;
				for (enemy3Iterator = enemy3Array.begin(); enemy3Iterator != enemy3Array.end(); enemy3Iterator++)
				{
					enemy3Array[counter].update();
					enemy3Array[counter].movement();
					window.draw(enemy3Array[counter].sprite);

					counter++;
				}



				//Tutorial way of drawing sprites, took out the whole render(window) thing by commenting it out below
				window.draw(Player.sprite);
				//Tutorial way of updating player
				Player.update();




				//Render(window);
				window.display();

				if (Paused == true)
				{
					window.draw(PauseText);
				}



			}

		}
	}
	return 0;
}





