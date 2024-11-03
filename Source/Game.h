#pragma once
#include "Car.h"
#include "GUI.h"
#include "Log.h"
#include "Frog.h"
#include "Screen.h"
#include "Pad.h"
#include <vector>
#include "GUI.h"

class Game 
{

	Frog frog;	
	GUI gui;

	Sound Goals;
	Sound Theme;

	std::vector<Car>Cars;
	std::vector<Log>Logs;
	std::vector<Pad>Pads;
	
	bool firsttime;
	bool onlog;

	
public:
	
	/*std::vector<Log>Log(Screen&screen);*/
	Game(Screen& screen);

	void Drawcars(Screen& screen);
	void Drawlogs(Screen& screen);
	void Drawmap(Screen& screen);
	void DrawGUI(Screen& screen);
	void Drawlilypad(Screen& screen);


	bool CheckCollision(const IntRect& colliderA, const IntRect& colliderB);
	bool Onwater(Screen& screen);
	
	void Frogoutofthemap(Screen& screen);
	void Frogandlogscollision(Screen& screen);
	void Frogandcarscollision(Screen& screen);
	void Frogandlilypadscollision(Screen& screen);
	void Frogdrowning(Screen& screen);
	

	void Setup(Screen& screen);
	void Update(Screen&screen/*,Frog& m_frog,Map&m_map,Log&m_log,Car&m_car*/);
};