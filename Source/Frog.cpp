#include "Frog.h"
#include <iostream>
bool Frog::Moving()
{
	return Magnitude(frogTexture.position - intendedPosition) > 1.0f;
}

float Frog::Jumplenght()
{
	//adjust frog jump distance here
	return 50;
}

Frog::Frog(Screen& screen) : position(frogTexture.position)
{
	position.x = 500;
	position.y = 975;
	frogTexture = screen.LoadSprite("assets/Frog.png");
	jumpSound = screen.LoadSound("assets/Jump.ogg");
	jumpSound.volume = { 200 };
	frogTexture.texture.src = { 0,0,50,50 };
	frogTexture.origin = { 25,25 };
	frogTexture.angle = 0;
	frogTexture.position = { position.x,position.y };
	frogDir = direction::up;
	jump = false;
	intendedPosition = frogTexture.position;
}

void Frog::Input(Screen& screen)
{
	if (!Moving())
	{
		screen.StopSound(jumpSound);
		if (screen.IsKeyDown(Key::Right))
		{
			frogDir = direction::right;
			jump = true;
		}
		else if (screen.IsKeyDown(Key::Left))
		{
			frogDir = direction::left;
			jump = true;
		}
		else if (screen.IsKeyDown(Key::Down))
		{
			frogDir = direction::down;
			jump = true;
		}
		else if (screen.IsKeyDown(Key::Up))
		{
			frogDir = direction::up;
			jump = true;
		}
	}
}

void Frog::Movement(Screen& screen)
{
	/*intendedPosition = Vector2{ screen.GetWindowWidth() / 2.0f, screen.GetWindowHeight() / 2.0f };*/

	frogTexture.position = Vector2::Lerp(frogTexture.position, intendedPosition, 0.2f);


		if (frogDir == direction::right && jump == true)
		{
			intendedPosition += Vector2(Jumplenght(), 0.0f);
			jump = false;
			screen.PlaySound(jumpSound);
		}
		if (frogDir == direction::left && jump == true)
		{
			intendedPosition += Vector2(-Jumplenght(), 0.0f);
			jump = false;
			screen.PlaySound(jumpSound);
		}
		if (frogDir == direction::down && jump == true)
		{
			intendedPosition += Vector2(0.0f, Jumplenght());
			jump = false;
			screen.PlaySound(jumpSound);
		}
		if (frogDir == direction::up && jump == true)
		{
			intendedPosition += Vector2(0.0f, -Jumplenght());
			jump = false;
			screen.PlaySound(jumpSound);
		}		
}

void Frog::Frogtele(Screen& screen)
{	
	frogTexture.position.x = 500;
	frogTexture.position.y = 975;
	intendedPosition.x = 500;
	intendedPosition.y = 975;
}


void Frog::Drawfrog(Screen& screen)
{	
	std::cout << frogTexture.position.y << std::endl;

	if (frogDir == direction::right)
	{
		frogTexture.angle = 90;
	}
	if (frogDir == direction::left)
	{
		frogTexture.angle = 270;
	}
	if (frogDir == direction::down)
	{
		frogTexture.angle = 180;
	}
	if (frogDir == direction::up)
	{
		frogTexture.angle = 0;
	}
	if (Moving())
	{		
		frogTexture.texture.src = { 50,50,50,50 };				
	}
	else
	{
		frogTexture.texture.src = { 0,0,50,50 };
	}
	screen.DrawSprite(frogTexture);
}


void Frog::Movementonlogs(Screen&screen, Log&log)
{
	intendedPosition.x = intendedPosition.x + log.Getlogsspeed();
	frogTexture.position.x= frogTexture.position.x + log.Getlogsspeed();
	
}

 

//Get and set for the frog

float Frog::Frogwidth(Screen& screen)
{
	return frogTexture.texture.width;
}

float Frog::Frogheight(Screen& screen)
{
	return frogTexture.texture.height;
}

float Frog::GetfrogX()
{
	return position.x;
}

float Frog::GetfrogY()
{
	return  position.y;
}

void Frog::SetfrogX(float x)
{
	position.x = x;
}

void Frog::SetfrogY(float y)
{
	position.y = y;
}

IntRect Frog::GetCollider()
{
	return IntRect{(int)frogTexture.position.x - frogTexture.texture.src. w / 4, (int)frogTexture.position.y+5 - frogTexture.texture.src.h / 2, frogTexture.texture.src.w/2, frogTexture.texture.src.h/2};
}


