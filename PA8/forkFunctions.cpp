#include "forkHeader.h"

bool fork::checkHit(moveableObject& inObject)
{
	if (this->getYcord() <= inObject.getYcord() + inObject.getBoxSize().y)
	{
		return true;
	}
	else
	{
		return false;
	}	
}