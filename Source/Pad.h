#pragma once
#include "Screen.h"


class Pad
{
	Sprite Padpic;
	Sprite Goals;
	Vector2 position;
public:
	bool goal=false;
	Pad(Screen& screen,int i,float posX,float posY);
	void Drawpad(Screen& screen);
	IntRect GetCollider();
};
