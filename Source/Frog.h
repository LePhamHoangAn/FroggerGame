#pragma once
#include "Screen.h"
#include "Log.h"


class Frog
{
	
	Sprite frogTexture;
	Vector2& position;
	Vector2 intendedPosition;
	IntRect frogPic;
	Sound jumpSound;
	enum direction{left,right,up,down};
	direction frogDir;
	bool jump;

	

public:
	Frog(Screen& screen);

	float Jumplenght();

	float Frogwidth(Screen& screen);
	float Frogheight(Screen& screen);

	float GetfrogX();
	float GetfrogY();
	void SetfrogX(float x);
	void SetfrogY(float y);

	
	bool Moving();

	IntRect GetCollider();



	void Frogtele(Screen& screen);
	void Input(Screen& screen);
	void Movement(Screen& screen);
	void Movementonlogs(Screen& screen, Log& log);
	void Drawfrog(Screen& screen);

};