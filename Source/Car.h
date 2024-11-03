#pragma once
#include "Screen.h"

class Car
{
	Vector2 position;	
	int Speed;
	int Size;
	Sprite Pic;

	float left()
	{
		return position.x;
	}
	float right()
	{
		return position.x + Pic.texture.width;
	}

	void SetLeft(float x)
	{
		position.x = x;
	}

	void SetRight(float x)
	{
		position.x = x - Pic.texture.width;
	}

public:
	Car(Screen&screen, int i, int posX, int posY, int speed, int size);

	IntRect GetCollider();


	void Carmoving(Screen& screen);
	void Drawcar(Screen& screen);
};