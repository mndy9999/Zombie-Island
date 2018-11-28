#include "Human.h"
#include "console.h"
#include <iostream>
#include <conio.h>
using namespace std;


Human::Human()
{
}


Human::~Human()
{
}

//get input, check if there is enough space, move.
void Human::move()
{
	char key = _getch();		//create a variable type char and wait for input

	Console::setCursorPosition(x, y);		//set the cursor position to the current values of x and y
	cout << " ";							//output a blank space

	switch (key)				//check which key was pressed and change the values of x and y accordingly
	{							//without surpassing the map boundaries
	case 'w': if (x > 4)
		x -= 1;
		break;
	case 's': if (x < 27)
		x += 1;
		break;
	case 'a': if (y > 2)
		y -= 1;
		break;
	case 'd': if (y < 98)
		y += 1;
		break;
	}
	Console::setCursorPosition(x, y);				//set cursor position to the new values of x and y
	Console::setColour(Console::LIGHT_GREEN);		//set a character-specific colour
	cout << "H";									//output the character symbol in the new position
}
