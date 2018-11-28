#include "Character.h"
#include "console.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

Character::Character()
{
	x = randX();			//give x a random value
	y = randY();			//give y a random value
}

Character::~Character()
{
}

int Character::randX()			
{
	rand();
	int randX = rand() % 24 + 4;		//generate a number between 4 and 28
	return randX;						//return the number
}

int Character::randY()
{
	rand();
	int randY = rand() % 95 + 3;		//generate a number between 3 and 98
	return randY;						//return the number
}

int Character::getPosX()
{
	return x;							//return value of x
}

int Character::getPosY()
{
	return y;							//return value of y
}

void Character::randSpawn(char symbol)
{
	Console::setCursorPosition(x, y);		//set the cursor position to x and y
	cout << symbol;							//output certain symbol
}


void Character::setPosX(int pX)
{
	x = pX;									//set value of x to pX
}

void Character::setPosY(int pY)
{
	y = pY;									//set value of y to pY
}

