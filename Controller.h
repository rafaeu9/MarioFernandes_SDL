/* Change Log
19/03/2020 - Structur and Input Enum 
*/

#pragma once
#include "SDL.h"
#include <iostream>

//Possible Inputs
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

	//Detect if button was pressed
	bool GetButton(Input Key);

	SDL_Joystick* joy;

	//ID of the crontroller
	int ID;

	//Buttons pressed
	bool m_ButtonPressed[INVALID];
	
};

