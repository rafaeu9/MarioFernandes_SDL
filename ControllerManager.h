#pragma once
#include <stdio.h>
#include <vector>
#include "SDL.h"
#include "Controller.h"

using namespace std;

class ControllerManager
{
private:

	SDL_Event* ev = new SDL_Event();

	SDL_Joystick* joy;

	int joyTotal;

public:

	ControllerManager();
	~ControllerManager();

	void init();
	void Update();

	std::vector<Controller*> controllers;

};

