#pragma once
#include "SDL.h"
#include <iostream>

enum Input
{
	A, B, Y, X, DOWN_ARROW, RIGHT_ARROW, UP_ARROW, LEFT_ARROW, INVALID
};


class Controller
{

	SDL_GameController* gamecontroller;
	SDL_GameControllerButton button;
	

public:

	Controller(SDL_Joystick* tempjoy, int inpID);

	bool GetButton(Input Key);


	SDL_Joystick* joy;

	int ID;

	bool m_ButtonPressed[INVALID];
	
};

