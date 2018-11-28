#include "Settings.h"
#include "console.h"
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

Settings::Settings()
{
}


Settings::~Settings()
{
}

//function that makes the underline disappear
void Settings::showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

//save user name in a log file
void Settings::saveName()
{
	Console::clear();			//clear the console

								//output directions
	Console::setCursorPosition(9, 30);
	cout << "Please enter your nickname: ";

	Console::setCursorPosition(15, 35);
	cout << "------------------";
	Console::setCursorPosition(24, 30);
	cout << "Press enter when finished...";

	//input the name
	Console::setCursorPosition(14, 40);
	string name;
	cin >> name;

	fstream logs;							//create the text file
	logs.open("logs.txt", fstream::app);	//open the text file and write on it without deleting the previous data
	logs << name << endl;					//write the information in the text file
}

//function that draws the map
void Settings::drawMap(int lenght, int height, char symbol)
{
	//top wall
	Console::setCursorPosition(3, 1);
	for (int i = 0; i < lenght; i++)
	{
		cout << symbol << " ";
	}
	//left wall
	for (int i = 3; i < height; i++)
	{
		Console::setCursorPosition(i, 1);
		cout << symbol;
	}
	//right wall
	for (int i = 3; i < height; i++)
	{
		Console::setCursorPosition(i, 99);
		cout << symbol;
	}
	//bottom wall
	Console::setCursorPosition(28, 1);
	for (int i = 0; i < lenght; i++)
	{
		cout << symbol << " ";
	}
}

//function that creates the first meny and asks for input
int Settings::firstMenu()
{

	Console::setCursorPosition(10, 40);
	cout << "1. Start";
	Console::setCursorPosition(15, 40);
	cout << "2. Load";
	Console::setCursorPosition(20, 40);
	cout << "3. Exit";

	char pick = _getch();
	return pick;
}

//function that outputs a message when the player wins
void Settings::winMessage()
{
	Console::clear();
	Console::setCursorPosition(15, 45);
	cout << "You won!!";
	Sleep(5000);		//sleep for 5 seconds before program exits
}

//function that outputs a message when the player loses
void Settings::loseMessage()
{
	Console::clear();
	Console::setCursorPosition(15, 45);
	cout << "You lost!!";
	Sleep(5000);		//sleep for 5 seconds before program exits
}

//function that outputs a message when the player chooses to load a saved game
void Settings::loadMessage()
{
	Console::clear();
	Console::setCursorPosition(13, 40);
	cout << "Feature coming soon!";
	Console::setCursorPosition(17, 40);
	cout << "Program will exit in:";
	Console::setCursorPosition(19, 50);
	cout << 5;
	Sleep(1000);
	Console::setCursorPosition(19, 50);
	cout << 4;
	Sleep(1000);
	Console::setCursorPosition(19, 50);
	cout << 3;
	Sleep(1000);
	Console::setCursorPosition(19, 50);
	cout << 2;
	Sleep(1000);
	Console::setCursorPosition(19, 50);
	cout << 1;
	Sleep(1000);
}