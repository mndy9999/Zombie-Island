#pragma once
#include "Character.h"

//this class inherits the functions from the Character class
class Zombie : public Character
{
private:
public:
	Zombie();
	~Zombie();

	void move();		//function that moves the zombies
};

