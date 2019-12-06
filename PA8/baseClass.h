#ifndef BASECLASS_H
#define BASECLASS_H

#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;

class moveableObject
{
private:
	string name;
	sf::RectangleShape box;
	sf::Texture boxTexture;

public:
	moveableObject();
	moveableObject(string inName, sf::RectangleShape inBox, sf::Texture inBoxTexture);
	~moveableObject();

	void setName(string inName);
	void setBox(sf::RectangleShape inBox);
	void setBoxTexture(sf::Texture inBoxTexture);

	string getName();
	sf::RectangleShape getBox();
	sf::Texture getBoxTexture();

	void rotateRect(int rotation);
	void texturePic();
	void updateCords(int inX, int inY);
	void changeBoxSize(sf::Vector2f newSize);
	void draw2Screen(sf::RenderWindow& window);
	void drawTexture();
	int getXcord();
	int getYcord();
	void setXcord(int inX);
	void setYcord(int inY);
	sf::Vector2f getBoxSize();
};

#endif // !BASECLASS_H