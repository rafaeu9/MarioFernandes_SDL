/* Change Log
20/03/2020 - Detect event and give it to the right controller
*/

#pragma once
#include <stdio.h>
#include <vector>
#include "SDL.h"
#include "Controller.h"

using namespace std;

class ControllerManager
{
private:

	SDL_Joystick* joy;

	//Total number of controllers 
	int joyTotal;

public:

	ControllerManager();
	~ControllerManager();

	void Update();

	static ControllerManager* controllermnager;

	//Events
	SDL_Event* ev = new SDL_Event();

	//List of controllers
	std::vector<Controller*> controllers;

};

