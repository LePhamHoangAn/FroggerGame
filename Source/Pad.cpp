#include "Pad.h"


Pad::Pad(Screen& screen, int i, float posX, float posY)
{
	position.x=posX ;
	position.y=posY ;
	if (i == 0)
	{
		Padpic = screen.LoadSprite("assets/lilypad.png");
		Goals = screen.LoadSprite("assets/cheems.png");
	}
	else if (i == 1)
	{
		Padpic = screen.LoadSprite("assets/lilypad.png");
		Goals = screen.LoadSprite("assets/cheems.png");

	}
	else if (i == 2)
	{
		Padpic = screen.LoadSprite("assets/lilypad.png");
		Goals = screen.LoadSprite("assets/cheems.png");

	}
	else if (i == 3)
	{
		Padpic = screen.LoadSprite("assets/lilypad.png");
		Goals = screen.LoadSprite("assets/cheems.png");

	}
	else if (i == 4)
	{
		Padpic = screen.LoadSprite("assets/lilypad.png");
		Goals = screen.LoadSprite("assets/cheems.png");

	}
}

void Pad::Drawpad(Screen& screen)
{
	
	if (goal)
	{
		screen.DrawSprite(Goals);
		Goals.position = {position};
	}
	else
	{
		screen.DrawSprite(Padpic);
		Padpic.position = { position };
	}
}

IntRect Pad::GetCollider()
{
	return IntRect{ (int)Padpic.position.x , (int)Padpic.position.y, Padpic.texture.src.w, Padpic.texture.src.h };
}