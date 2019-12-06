#ifndef PLAYERHEADER_H
#define PLAYERHEADER_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include "baseClass.h"
using namespace std;

class player:public moveableObject
{
public:
	void openMouth();
	void closeMouth();
};

#endif // !BASECLASS_H