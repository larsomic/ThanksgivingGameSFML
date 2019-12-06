#include "playerHeader.h"

void player::openMouth()
{
	string tempString;

	tempString = this->getName();
	if (tempString == "Andy")
	{
		tempString = tempString + "Mouth";
	}
	else if (tempString == "Nadra")
	{
		tempString = tempString + "Mouth";
	}
	
	this->setName(tempString);
	this->texturePic();
	this->drawTexture();
}

void player::closeMouth()
{
	string tempString;

	tempString = this->getName();

	if (tempString == "AndyMouth")
	{
		tempString = "Andy";
	}
	else if (tempString == "NadraMouth")
	{
		tempString = "Nadra";
	}

	this->setName(tempString);
	this->texturePic();
	this->drawTexture();
}