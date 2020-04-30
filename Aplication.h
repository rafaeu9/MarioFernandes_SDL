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

#include "SDL.h"
#include "Components.h"
#include "Map.h"
#include "ControllerManager.h"
#include "FileIO.h"


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
	static CollisionManager* collisionManger;
	/*static Controller* controller;*/
	

private:

	SDL_Window* window;

	ControllerManager* controllerManager;

	Manager manager;
		
	Map* map;

	/*Entity& Player;*/

	// State of the app
	bool isRunning = false;

	//Run aplication
	void Running();

	void CreateEnteties();

	void Update();
	void Draw();

	void End();
};

