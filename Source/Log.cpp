#include "Log.h"


Log::Log(Screen& screen, int i, int posX, int posY, int speed, int size)
{
	position.x= posX;
	position.y= posY;
	Speed= speed;
	Size= size;
	if (i == 0)
	{
		logPic = screen.LoadSprite("assets/log1.png");
		logPic.origin = { 200,25 };
	}
	else if (i == 1)
	{
		logPic = screen.LoadSprite("assets/log1.png");
		logPic.origin = { 200,25 };
	}
	else if (i == 2)
	{
		logPic = screen.LoadSprite("assets/log1.png");
		logPic.origin = { 200,25 };
	}
	else if (i == 3)
	{
		logPic = screen.LoadSprite("assets/log1.png");
		logPic.origin = { 200,25 };
	}
	else if (i == 4)
	{
		logPic = screen.LoadSprite("assets/log2.png");
		logPic.origin = { 300,25 };
	}
	else if (i == 5)
	{
		logPic = screen.LoadSprite("assets/log2.png");
		logPic.origin = { 300,25 };
	}
	else if (i == 6)
	{
		logPic = screen.LoadSprite("assets/log2.png");
		logPic.origin = { 300,25 };
	}
	else if (i == 7)
	{
		logPic = screen.LoadSprite("assets/log2.png");
		logPic.origin = { 300,25 };
	}
}

void Log::Logmoving(Screen& screen)
{
	position.x = position.x + Speed;
	if (left() > screen.GetWindowWidth())
	{
		SetRight(0.0f);
	}
	if (right() < 0)
	{
		SetLeft(screen.GetWindowWidth());
	}
}

void Log::Drawlog(Screen& screen)
{
		screen.DrawSprite(logPic);
		logPic.position = { position };
}

float Log::Logwidth(Screen& screen)
{
	return logPic.texture.width;
}

float Log::Logheight(Screen& screen)
{
	return logPic.texture.height;
}

//Get and set functions
float Log::GetlogX()
{
	return position.x;
}
float Log::GetlogY()
{
	return position.y;
}
void Log::SetlogX(float x)
{
	position.x = x;
}
void Log::SetlogY(float y)
{
	position.y = y;
} 
float Log::Getlogsspeed()
{
	return Speed;
}

IntRect Log::GetCollider()
{
	return IntRect{ (int)logPic.position.x - logPic.texture.src.w / 2, (int)logPic.position.y - logPic.texture.src.h / 2, logPic.texture.src.w, logPic.texture.src.h };
}