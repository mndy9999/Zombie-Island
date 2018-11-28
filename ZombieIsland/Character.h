#pragma once
class Character
{
protected:
	int x, y;
public:
	Character();
	~Character();

	int randX();			//generates random x
	int randY();			//generates random y
	int getPosX();			//gets the x value
	int getPosY();			//gets the y value

	void randSpawn(char);		//spawns characters in random places

	void setPosX(int);		//sets tge x value
	void setPosY(int);		//sets the y value
};

