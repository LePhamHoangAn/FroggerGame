#pragma once
#include "Screen.h"

class GUI
{
	Sprite heart1;
	Sprite heart2;
	Sprite heart3;

	
	int lives;
public:
	bool victory;
	bool gamestart;
	GUI(Screen& screen);
	void Gamestarter(Screen& screen);
	void Livesmanager(Screen& screen);
	void Drawgui1(Screen&screen);
	void Drawgui2(Screen&screen);
	void Drawgui3(Screen&screen);
	void Takedamage(int damage); 
	bool Frogdeath();
};
