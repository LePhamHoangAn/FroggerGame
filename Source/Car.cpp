#include "Car.h"


Car::Car(Screen& screen, int i,int posX,int posY,int speed,int size)
{
	Pic = screen.LoadSprite("assets/car" + std::to_string(i + 1) + ".png");
	position.x = posX;
	position.y = posY;
	Speed = speed;
	Size = size;
}

void Car::Carmoving(Screen& screen)
{
	position.x = position.x+Speed;
	if (left() > screen.GetWindowWidth())
	{
		SetRight(0.0f);
	}
	if (right()  < 0)
	{
		SetLeft(screen.GetWindowWidth());
	}
}

void Car::Drawcar(Screen& screen)
{
	screen.DrawSprite(Pic);
	Pic.position = {position};	
}

IntRect Car::GetCollider()
{
	return IntRect{ (int)position.x, (int)position.y , Pic.texture.src.w, Pic.texture.src.h };
}
