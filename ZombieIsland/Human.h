#pragma once
#include "Character.h"

//this class inherits the functions from the Character class
class Human : public Character
{
public:
	Human();
	~Human();

	void move();		//function that moves the human
};

