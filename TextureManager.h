#pragma once
#include <iostream>
#include <stdio.h>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include "Aplication.h"

/*
ChangeLog
09/04/2020 - PNG/JPG Suport
*/

class TextureManager
{
public:

	static SDL_Texture* LoadBMPTexture(const char* FileName, SDL_Rect* destRect = nullptr, bool Transparency = false);

	static SDL_Texture* LoadIMGTexture(const char* FileName, SDL_Rect* destRect = nullptr, bool Transparency = false);

	static void Draw(SDL_Texture* tex, SDL_Rect dest);

};

