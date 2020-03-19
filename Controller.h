#pragma once
#include "SDL.h"
#include <iostream>

enum class Input
{
	INVALID, A, B, Y, X, DOWN_ARROW, RIGHT_ARROW, UP_ARROW, LEFT_ARROW
};


class Controller
{
	Input input = Input::INVALID;

	SDL_GameController* gamecontroller;
	SDL_GameControllerButton button;

	SDL_Event event;

public:
	Controller(SDL_Joystick* tempjoy, int inpID);
	SDL_Joystick* joy;
	int ID;
	Input GetButton();
};

