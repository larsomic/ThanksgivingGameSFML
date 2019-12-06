#ifndef MONSTERHEADER_H
#define MONSTERHEADER_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include "baseClass.h"
using namespace std;

class monster :public moveableObject
{
private:
		int score;

public:
	void setScore(int score);
	int getScore();
};

#endif // !MONSTERHEADER_H