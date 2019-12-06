#include "PA8Header.h"
#include "baseClass.h"

moveableObject::moveableObject()
{
	name = "unitialized";
}

moveableObject::moveableObject(string inName, sf::RectangleShape inBox, sf::Texture inBoxTexture)
{
	name = inName;
	box = inBox;
	boxTexture = inBoxTexture;
}

moveableObject::~moveableObject()
{

}

void moveableObject::setName(string inName)
{
	name = inName;
}

void moveableObject::setBox(sf::RectangleShape inBox)
{
	box = inBox;
}

void moveableObject::setBoxTexture(sf::Texture inBoxTexture)
{
	boxTexture = inBoxTexture;
}

string moveableObject::getName()
{
	return name;
}

sf::RectangleShape moveableObject::getBox()
{
	return box;
}

sf::Texture moveableObject::getBoxTexture()
{
	return boxTexture;
}

void moveableObject::rotateRect(int rotation)
{
	box.setRotation(rotation);
}

void moveableObject::texturePic()
{
	string tempName;
	tempName = name + ".png";
	boxTexture.loadFromFile(tempName);
}

void moveableObject::updateCords(int inX, int inY)
{
	box.setPosition(sf::Vector2f(inX, inY));
}

void moveableObject::changeBoxSize(sf::Vector2f newSize)
{
	box.setSize(newSize);
}

void moveableObject::draw2Screen(sf::RenderWindow& window)
{
	window.draw(box);
}

void moveableObject::drawTexture()
{
	box.setTexture(&boxTexture);
}

int moveableObject::getXcord()
{
	return this->box.getPosition().x;
}

int moveableObject::getYcord()
{
	return this->box.getPosition().y;
}

void moveableObject::setXcord(int inX)
{
	
	this->box.setPosition(sf::Vector2f(inX, this->box.getPosition().y));
}

void moveableObject::setYcord(int inY)
{
	this->box.setPosition(sf::Vector2f(this->box.getPosition().x, inY));
}

sf::Vector2f moveableObject::getBoxSize()
{
	return box.getSize();
}
