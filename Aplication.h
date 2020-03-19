#pragma once
#include <iostream>
#include <conio.h>

#include "SDL.h"


class Aplication
{
public:

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	static SDL_Renderer* renderer;

private:

	SDL_Window* window;

	void Update();
	void Draw();
};

