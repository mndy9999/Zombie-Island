
//this class sets up the settings
class Settings
{
public:
	Settings();
	~Settings();
	void showConsoleCursor(bool);		//makes flickering underline disappear
	void saveName();					//save the player name
	int firstMenu();					//creates the first menu
	void loadMessage();					//outputs loading message
	void drawMap(int, int, char);		//draws the map
	void winMessage();					//outputs win message
	void loseMessage();					//outputs lose message
};
