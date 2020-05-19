/* Change Log
19/03/2020 - Structure of the class, window and FPS
26/03/2020 - Add Map Class
26/03/2020 - Start Colision and colision manager
04/03/2020 - Add Player entity
*/

#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <String>

#include "SDL.h"
#include "Components.h"
#include "Map.h"
#include "ControllerManager.h"


using namespace std;

class Map;
class CollisionManager;

class Aplication
{
public:

	Aplication();

	
	/* 
	Initialize aplication
	- Title of the Window
	- Position X on screen
	- Position Y on screen
	- With of the window
	- Height of the window
	- Fullscreen
	*/
	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	static SDL_Renderer* renderer;
	
	static bool isRunning;

private:

	SDL_Window* window;

	ControllerManager* controllerManager;

	Manager manager;
		
	Map* map;
	
	//Run aplication
	void Running();

	//Create the enteties of the game
	void CreateEnteties();

	//Update the game
	void Update();

	//Draw the game
	void Draw();

	//Close the game
	void End();
};

