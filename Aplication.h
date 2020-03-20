#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>

#include "SDL.h"
////#include "Map.h"
#include "ControllerManager.h"

using namespace std;

class Aplication
{
public:

	Aplication();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	static SDL_Renderer* renderer;
	/*static Controller* controller;*/

private:

	SDL_Window* window;

	ControllerManager* controllerManager;
	/*Map* map;	*/

	bool isRunning = false;

	void Running();

	void Update();
	void Draw();

	void End();
};

