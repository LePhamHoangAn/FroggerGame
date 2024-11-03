#include "Game.h"


Game::Game(Screen& screen) : frog(screen),gui(screen)
{
	firsttime = true;
	onlog = false;

	Goals = screen.LoadSound("assets/home.wav");
	Goals.volume = { 100 };

	Theme = screen.LoadSound("assets/theme.ogg");
	Theme.volume = { 50 };
	Theme.looping = true;

	Setup(screen);
	
}

void Game::Setup(Screen& screen)
{

	//for the cars
	for (int i = 0; i < 3; i++)
	{
		int posX = 100 + 100 * i;
		int posY = (screen.GetWindowHeight() - 100) - 50 * i;
		int speed = rand() % +5 - i;
		int size = 50;
		Car car(screen, i, posX, posY, speed, size);
		Cars.push_back(car);
	}
	for (int i = 3; i < 5; i++)
	{
		int posX = 100 + 100 * i;
		int posY = (screen.GetWindowHeight() - 100) - 50 * i;
		int speed = -rand() % +5 - i;
		int size = 50;
		Car car(screen, i, posX, posY, speed, size);
		Cars.push_back(car);
	}
	//for the logs
	for (int i = 0; i < 8; i++)  //going 
	{
		int posX = 100 + 100 * i;
		int posY = (screen.GetWindowHeight() / 2-25) - 50* i;
		int speed = rand() % 3+1;
		speed *= i % 2 == 0 ? 1 : -1;
		int size = 50;
		Log log(screen, i, posX, posY, speed, size);
		Logs.push_back(log);
	}
	/*for (int i = 4; i < 8; i++)
	{
		int posX = 100 + 100 * i;
		int posY = (screen.GetWindowHeight() / 2 -25) - 50 * i;
		int speed = rand() % 3+1;
		int size = 50;
		Log log(screen, i, posX, posY, -speed, size);
		Logs.push_back(log);
	}*/
	
	//for the lilypads
	for (int i = 0; i < 5; i++)
	{
		int posX = 100 + 200 * i;
		int posY =25;	
		Pad pad(screen, i, posX, posY);
		Pads.push_back(pad);
	}
	frog.Frogtele(screen);
}

bool Game::CheckCollision(const IntRect& colliderA, const IntRect& colliderB)
{
	//in screen.h
	if (colliderA.top() > colliderB.bottom()) return false;
	if (colliderA.bottom() < colliderB.top()) return false;
	if (colliderA.left() > colliderB.right()) return false;
	if (colliderA.right() < colliderB.left()) return false;
	return true;
}


void Game::Frogandlogscollision(Screen& screen)
{
	onlog = false;
	for (Log& log : Logs)  //for each log in the vector 
	{
		if (CheckCollision(frog.GetCollider(), log.GetCollider()))
		{
			frog.Movementonlogs(screen, log);
			onlog = true;
		}
	}
}

void Game::Frogandcarscollision(Screen& screen)
{
	for (Car& car : Cars)  //for each car in the vector 
	{
		if (CheckCollision(frog.GetCollider(), car.GetCollider()))
		{
			frog.Frogtele(screen);	
			gui.Takedamage(1);
		}
	}
}

void Game::Frogandlilypadscollision(Screen& screen)
{
	for (Pad& pad : Pads)  //for each car in the vector 
	{
		if (CheckCollision(frog.GetCollider(), pad.GetCollider()))
		{
			frog.Frogtele(screen);
			pad.goal = true;
			screen.PlaySound(Goals);
		}
	}
}

void Game::Frogoutofthemap(Screen& screen)
{
	if (frog.GetfrogX() > screen.GetWindowWidth() || frog.GetfrogX() < 0 || frog.GetfrogY() > screen.GetWindowHeight() || frog.GetfrogY() < 0)
	{
		frog.Frogtele(screen);
		gui.Takedamage(1);
	}
}

bool Game::Onwater(Screen& screen)
{
	if (frog.GetfrogY() < (screen.GetWindowHeight() / 2))
	{
		return true;
	}
	if (frog.GetfrogY() < (screen.GetWindowHeight() / 2) && onlog == true)
	{
		return false;
	}
}


void Game::Frogdrowning(Screen& screen)
{
	if (Onwater(screen)==true&&!onlog)
	{
		frog.Frogtele(screen);
		gui.Takedamage(1);
	}
}



void Game::Drawcars(Screen& screen)
{
	for (int i = 0; i < 5; i++)
	{
		Cars[i].Drawcar(screen);
	}
}

void Game::Drawlogs(Screen& screen)
{
	for (int i = 0; i < 8; i++)
	{
		Logs[i].Drawlog(screen);
	}
}

void Game::Drawlilypad(Screen& screen)
{
	for (int i = 0; i < 5; i++)
	{
		Pads[i].Drawpad(screen);
	}
}


void Game::DrawGUI(Screen& screen)
{	
	gui.Livesmanager(screen);
}

void Game::Drawmap(Screen& screen)
{
	
	//water
	screen.DrawRectangle(0, 0, screen.GetWindowWidth(), screen.GetWindowHeight() / 2, 0, 0, 255, 255);
	//grass in the middle
	screen.DrawRectangle(0, screen.GetWindowHeight() / 2, screen.GetWindowWidth(), screen.GetWindowHeight() /6, 0, 255, 0, 255);
	//grass up top
	screen.DrawRectangle(0, 0, screen.GetWindowWidth(), (screen.GetWindowHeight() / 10), 0, 255, 0, 255);
	
}

void Game::Update(Screen& screen)
{

	//INPUT
	frog.Input(screen);
	gui.Gamestarter(screen);



	//LOGIC
	Game::Frogandlogscollision(screen);
	Game::Frogandcarscollision(screen);
	Game::Frogandlilypadscollision(screen);
	Game::Frogdrowning(screen);
	Game::Frogoutofthemap(screen);
	frog.Movement(screen);
	for (Car& car : Cars)  //for each car in the vector 
	{
		car.Carmoving(screen);
	}
	for (Log& log : Logs)  //for each log in the vector 
	{
		log.Logmoving(screen);
	}
	for (int i = 0; i < 5; i++)
	{		
		if (Pads[0].goal == true&& Pads[1].goal == true && Pads[2].goal == true && Pads[3].goal == true && Pads[4].goal == true)
		{
			gui.victory = true;
		}
	}


	//DRAW
	if (gui.Frogdeath())
	{
		screen.DrawText(500, 500, 255, 0, 0, 255, "LOSE");
	}
	if (gui.gamestart==false)
	{
		screen.DrawText(400, 500, 0, 255, 0, 255, "FROGGER");
		screen.DrawText(300, 550, 255,0, 0, 255, "press enter to start");
	}
	if (gui.victory == true)
	{
		screen.DrawText(500, 500,0, 255, 0, 255, "VICTORY!!!!!");
	}
	if(gui.Frogdeath()==false && gui.gamestart==true &&gui.victory==false)
	{
		screen.PlaySound(Theme);
		Game::Drawmap(screen);			
		Game::DrawGUI(screen);
		Game::Drawlilypad(screen);
		Game::Drawcars(screen);
		Game::Drawlogs(screen);

		//collisionboxes

		//screen.DrawRectangle(frog.GetCollider());
		//for (Log& log : Logs)  //for each log in the vector 
		//{
		//	screen.DrawRectangle(log.GetCollider());
		//}
		//for (Car& car : Cars)  //for each car in the vector 
		//{
		//	screen.DrawRectangle(car.GetCollider());
		//}
		//for (Pad& pad : Pads)  //for each pad in the vector 
		//{
		//	screen.DrawRectangle(pad.GetCollider());
		//}
		
		frog.Drawfrog(screen);

	}
	
}