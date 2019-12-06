#ifndef FORKHEADER_H
#define FORKHEADER_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include "baseClass.h"
using namespace std;

class fork:public moveableObject
{
public:
	bool checkHit(moveableObject& inObject);
};

#endif // !BASECLASS_H