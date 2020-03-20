#pragma once
#include "SDL.h"
#include <iostream>

enum Input
{
	A, B, Y, X, DOWN_ARROW, RIGHT_ARROW, UP_ARROW, LEFT_ARROW, INVALID
};


class Controller
{
	Input input = Input::INVALID;

	SDL_GameController* gamecontroller;
	SDL_GameControllerButton button;
	

public:

	Controller(SDL_Joystick* tempjoy, int inpID);
	SDL_Joystick* joy;
	int ID;
	bool GetButton(Input Key);

	bool m_ButtonPressed[INVALID];
	
};

