#include <iostream>
#include <ctime>
#include <conio.h>
#include <vector>
#include <process.h>
#include <fstream>
#include <string>
#include "console.h"
#include "Settings.h"
#include "Character.h"
#include "Human.h"
#include "Zombie.h"
#include "Hole.h"
#include "Data.h"
using namespace std;

void difficulty(int &zombieCount, int &holeCount);
void spawn(Settings &map, Human &human, vector <Zombie> &zombieVec, vector <Hole> &holeVec, int &zombieCount, int &holeCount);
void move(Settings &map, Human &human, vector <Zombie> &zombieVec, vector <Hole> &hole, int &zombieCount, int &holeCount);
void save (Human &human, vector <Zombie> &zombieVec, vector <Hole> &holeVec, int &zombieCount, int &holeCount);
void load(Human &human, vector <Zombie> &zombieVec, vector <Hole> &holeVec, int &zombieCount, int &holeCount);

int main()
{
	srand(time(NULL));							//set the seed for the random numbers generators
	Console::setTextBufferSize(30, 101);		//set the console buffer size
	Console::setWindowTitle("Zombie Island");	//set the window title

	Settings map;							//create the map
	map.showConsoleCursor(false);			//make flickering underline disappear

	int zombieCount = 0;					//create variable that will hold the number of zombies
	int holeCount = 0;						//create variable that will hold the number of holes

	Human human;							//create the human
	vector <Zombie> zombieVec;				//create a vector for the zombies
	vector <Hole> holeVec;					//create a vector for the holes

	int input = map.firstMenu();			//display the first menu and choose a tab


	switch (input)
	{
	case '1':
		map.saveName();								//save the name of the player
		difficulty(zombieCount, holeCount);			//choose the difficulty
		spawn(map, human, zombieVec, holeVec, zombieCount, holeCount);			//spawn the characters
		move(map, human, zombieVec, holeVec, zombieCount, holeCount);			//move the characters
		break;
	case '2':
		map.loadMessage();				//display a message for the laod function that is not yet implemented
		break;

/*		This was supposed to load the position of every character and output them in the console then simply continue the game
		Console::clear();
		map.drawMap(49, 29, '\xFE');
		load(human, zombieVec, holeVec, zombieCount, holeCount);
		move(map, human, zombieVec, holeVec, zombieCount, holeCount);
		break;
*/
	case '3':
		return 0;			//exit
		break;
	}
}

//set the game difficulty
void difficulty(int &zombieCount, int &holeCount)
{
	Console::clear();				//clear the console

	cout << "Please choose a difficulty: ";			//output suitable messages
	Console::setCursorPosition(10, 40);
	cout << "1. Easy";
	Console::setCursorPosition(15, 40);
	cout << "2. Normal";
	Console::setCursorPosition(20, 40);
	cout << "3. Hard";

	char input = _getch();				//wait for character input
										//depending on the input, set the number of holes and zombies
	if (input == '1')
	{
		zombieCount = 10;
		holeCount = 5;
	}
	else if (input == '2')
	{
		zombieCount = 15;
		holeCount = 7;
	}
	else if (input == '3')
	{
		zombieCount = 20;
		holeCount = 10;
	}
}

//spawn the characters
void spawn(Settings &map, Human &human, vector <Zombie> &zombieVec, vector <Hole> &holeVec, int &zombieCount, int &holeCount)
{
	zombieVec.resize(zombieCount);			//set the size of the zombie vector
	holeVec.resize(holeCount);				//set the size of the hole vector

	Console::clear();						//clear console
	map.drawMap(49, 29, '\xFE');			//draw the map

	Console::setColour(Console::LIGHT_GREEN);			//set certain colour for the character spawn
	human.randSpawn('H');								//spawn the human in a random place
	for (int i = 0; i < zombieCount; i++)
	{
		Console::setColour(Console::LIGHT_RED);			//set certain colour for the character spawn
		zombieVec[i].randSpawn('Z');					//spawn zombies one by one
	}
	for (int i = 0; i < holeCount; i++)
	{
		Console::setColour(Console::LIGHT_PURPLE);			//set certain colour for the character spawn
		holeVec[i].randSpawn('O');							//spawn holes one by one
	}
}

//move the human and zombies
void move(Settings &map, Human &human, vector <Zombie> &zombieVec, vector <Hole> &holeVec, int &zombieCount, int &holeCount)
{
	
	while (zombieCount > 0)					//loop until all zombies are dead
	{
		save(human, zombieVec, holeVec, zombieCount, holeCount);		//save game data after every move
		Console::setColour(Console::LIGHT_GREEN);						//set colour for the zombies number output
		Console::setCursorPosition(1, 1);
		cout << "Zombies left: " << zombieCount << " ";					//output the number of zombies left in game

		human.move();										//move the human depending on the input
		for (int i = 0; i < zombieCount; i++)
		{
			zombieVec[i].move();							//move each zombie randomly
			for (int j = 0; j < holeCount; j++)
			{		//check if a hole and a zombie are on the same spot
				if (holeVec[j].getPosX() == zombieVec[i].getPosX() && holeVec[j].getPosY() == zombieVec[i].getPosY())
				{
					zombieCount--;									//subtract 1 from zombieCount
					zombieVec.erase(zombieVec.begin() + i);			//delete the appropiate zombie
					for (int h = 0; h < zombieCount; h++)			//push back the zombies so there is no empty space in the vector
					{
						zombieVec.push_back(Zombie());
					}
					//re-output the hole symbol in the same place after the zombie dies
					Console::setCursorPosition(holeVec[j].getPosX(), holeVec[j].getPosY());
					Console::setColour(Console::LIGHT_PURPLE);
					cout << "O";
				}
				//check if the human and a hole are in the same spot
				if (holeVec[j].getPosX() == human.getPosX() && holeVec[j].getPosY() == human.getPosY())
				{
					//output lose message and exit game
					Console::setColour(Console::LIGHT_PURPLE);
					map.loseMessage();
				}
				//check if the human and a zombie are in the same spot
				if (human.getPosX() == zombieVec[i].getPosX() && human.getPosY() == zombieVec[i].getPosY())
				{
					//output lose message and exit game
					Console::setColour(Console::LIGHT_RED);
					map.loseMessage();
				}
			}
		}
	}
	//if all the zombies are dead, the while loop ends and the game displays a winning message
	Console::setColour(Console::LIGHT_AQUA);
	map.winMessage();

}

//save the game progess
void save(Human &human, vector <Zombie> &zombieVec, vector <Hole> &holeVec, int &zombieCount, int &holeCount)
{
	ofstream save;				//create the text file
	save.open("save.txt");		//open the text file and overwrite the new information in it
	save << human.getPosX() << " " << human.getPosY() << endl;		//save the human position
	for (int i = 0; i < zombieCount; i++)
	{
		save << zombieVec[i].getPosX() << " " << zombieVec[i].getPosY() << endl;		//save the position for each of the zombies
	}
	for (int i = 0; i < holeCount; i++)
	{
		save << holeVec[i].getPosX() << " " << holeVec[i].getPosY() << endl;			//save the position for each of the holes
	}
}

//load the game (DOESN'T WORK YET)
void load(Human &human, vector <Zombie> &zombieVec, vector <Hole> &holeVec, int &zombieCount, int &holeCount)
{
	int x, y;
	ifstream save;
	save.open("save.txt");

	int index = 0;
	while (!save.eof())
	{
		while (index < 1)
		{
			save >> x;					//get x from the text file
			save >> y;					//get y from the text file
			human.setPosX(x);			//set x position to x
			human.setPosY(y);			//set y position to y
			human.randSpawn('H');		//spawn the character accordingly
			index++;
		}
		while (index > 0 && index < zombieCount);
		{
			for (int i = 0; i < zombieCount; i++)
			{
				save >> x;
				save >> y;
				zombieVec[i].setPosX(x);
				zombieVec[i].setPosY(y);
				zombieVec[i].randSpawn('Z');
				index++;
			}
		}
		while (index > (zombieCount + 1) && index < (zombieCount + holeCount + 1))
		{
			for (int i = 0; i < holeCount; i++)
			{
				save >> x;
				save >> y;
				holeVec[i].setPosX(x);
				holeVec[i].setPosY(y);
				holeVec[i].randSpawn('O');
				index++;
			}
		}
	}
}