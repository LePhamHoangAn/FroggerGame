#pragma once

#include "Screen.h"

class Log
{
	Vector2 position;
	int Speed;
	int Size;
	Sprite logPic;
	Sprite logPic2;
	

	float left()
	{
		return position.x - logPic.texture.width/2;
	}
	float right()
	{
		return position.x + logPic.texture.width;
	}

	void SetLeft(float x)
	{
		position.x = x + logPic.texture.width / 2;
	}

	void SetRight(float x)
	{
		position.x = x - logPic.texture.width;
	}

public:

	float Logwidth(Screen& screen);
	float Logheight(Screen& screen);

	IntRect GetCollider();

	float GetlogX();
	float GetlogY();
	void SetlogX(float x);
	void SetlogY(float y);
	float Getlogsspeed();

	Log(Screen& screen,int i, int posX, int posY, int speed, int size);
	void Logmoving(Screen& screen);
	/*void Collisionwithfrog();*/
	void Drawlog(Screen& screen);
};