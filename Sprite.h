#pragma once
#include "TextureManager.h"
#include "Components.h"
#include "SDL.h"

/*
Change Log
08/04/2020 - Ad an image to the Entity

*/

class Sprite :	public Component
{
private:
	
	Position* position;
	   
	SDL_Texture* Texture;	

public:

	SDL_Rect srcRect, destRect;
	

	Sprite();
	Sprite(const char* path, bool useTransparency = false);

	void setTex(const char* path, bool useTransparency = false);

	void init();

	void update();

	void draw();

	void rotation();

};
