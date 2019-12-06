#ifndef PA8HEADER_H
#define PA8HEADER_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "monsterHeader.h"
#include "baseClass.h"
#include "playerHeader.h"
#include "forkHeader.h"
#include "baseClass.h"
using namespace std;

void mainMenu(sf::RenderWindow& window, sf::Font font);
void playGame(sf::RenderWindow& window, int whoIsChar);
int characterChooser(sf::RenderWindow& window);
void getHostOrJoin(sf::RenderWindow& window, sf::Font font);
void originalWindow(sf::RenderWindow& window, sf::RectangleShape background, moveableObject &inObject);
int getRand(int x);
void makeRow(monster cardA[], int randInt, int num);
void displayRow(monster cardA[], int num, sf::RenderWindow& window);
bool moveRow(monster cardA[], int num, sf::RenderWindow & window, bool atEnd);
bool checkGameOver(monster cardA[], int num);

#endif // !PA8HEADER_H