#include "Zombie.h"
#include "console.h"
#include <cstdlib>
#include <iostream>
using namespace std;


Zombie::Zombie()
{

}


Zombie::~Zombie()
{
}

//move the zombie by 1 in a random direction
void Zombie::move()
{
	Console::setCursorPosition(x, y);		//set the cursor position to the current values of x and y
	cout << " ";							//output a blank space

	int chance = rand() % 8;				//generate a random number between 0 and 8
											//and move accordingly
	if (chance == 0)
	{
		if (x < 27)
		{
			x += 1;
		}
		if (y < 98)
		{
			y += 1;
		}
	}
	else if (chance == 1)
	{
		if (x > 4)
		{
			x -= 1;
		}
		if (y > 2)
		{
			y -= 1;
		}
	}
	else if (chance == 2)
	{
		if (x < 27)
		{
			x += 1;
		}
		if (y > 2)
		{
			y -= 1;
		}
	}
	else if (chance == 3)
	{
		if (x > 4)
		{
			x -= 1;
		}
		if (y < 98)
		{
			y += 1;
		}
	}
	else if (chance == 4)
	{
		if (x < 27)
		{
			x += 1;
		}
	}
	else if (chance == 5)
	{
		if (x > 4)
		{
			x -= 1;
		}
	}
	else if (chance == 6)
	{
		if (y < 98)
		{
			y += 1;
		}
	}
	else if (chance == 7)
	{
		if (y > 2)
		{
			y -= 1;
		}
	}
	//if chance = 8, the zombie doesn't move

	Console::setCursorPosition(x, y);				//set cursor position to the new values of x and y
	Console::setColour(Console::LIGHT_RED);			//set a character-specific colour
	cout << "Z";									//output the character symbol in the new position
}