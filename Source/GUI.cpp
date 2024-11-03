#include "GUI.h"

GUI::GUI(Screen& screen)
{
	//for the hearts
	lives = 3;
	gamestart = false;
	victory = false;
		heart1 = screen.LoadSprite("assets/heart.png");
		heart1.position={ 0,10 };
	
		heart2 = screen.LoadSprite("assets/heart.png");
		heart2.position = { 35,10 };
	
		heart3 = screen.LoadSprite("assets/heart.png");
		heart3.position = { 70,10 };
	
	
}

void GUI::Livesmanager(Screen&screen)
{
	if (lives == 3)
	{
		Drawgui1(screen);
		Drawgui2(screen);
		Drawgui3(screen);
	}
	if (lives == 2)
	{
		Drawgui1(screen);
		Drawgui2(screen);
	}
	if (lives == 1)
	{
		Drawgui1(screen);
	}
	
}


void GUI::Drawgui1(Screen& screen)
{
	screen.DrawSprite(heart1);
}

void GUI::Drawgui2(Screen& screen)
{
	screen.DrawSprite(heart2);
}

void GUI::Drawgui3(Screen& screen)
{
	screen.DrawSprite(heart3);
}
void GUI::Takedamage(int damage)
{
	lives-=damage;
}
bool GUI::Frogdeath()
{
	if (lives <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GUI::Gamestarter(Screen& screen)
{
	if (screen.IsKeyDown(Key::Enter))
	{
		gamestart = true;
	}
}

