#pragma once
#include "Components.h"
#include "Controller.h"

/*
Changelog 
14/04/2020 - Creat movemte Class with the direction functions and update using the controller arrows
*/

class Movement :
	public Component
{
public:

	Movement(Controller* controller_ID = nullptr);

	void update();

	int Speed;

private:

	Controller* controller;
	Position* Pos;
	


	void Up();
	void Down();
	void Left();
	void Right();
};

