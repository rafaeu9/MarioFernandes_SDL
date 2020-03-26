/* Change Log
26/03/2020 - Start Colision
*/
#pragma once
#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"
#include "CollisionManager.h"

class Collision :
	public Component
{
private:
	Position* pos;

public:

	SDL_Rect Rect;

	Collision(int Inp_h, int Inp_w);

	Collision(const char* path);

	void init();
	void update();
	void draw();

	void Square();
};

