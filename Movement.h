#pragma once
#include "Components.h"
#include "Controller.h"
#include "Map.h"

/*
Changelog 
14/04/2020 - Creat movemte Class with the direction functions and update using the controller arrows
*/

class Map;

class Movement :
	public Component
{
public:

	Movement(Map* Inp_map, Controller* controller_ID = nullptr);

	void update();

	int Speed;

private:

	Controller* controller;
	Position* Pos;
	Position LastPos;

	Map* map;


	void Up();
	void Down();
	void Left();
	void Right();
};

