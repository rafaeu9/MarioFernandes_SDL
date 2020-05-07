/* Change Log
26/03/2020 - Load map Texture, Create map Based on Array and draw on screen
17/04/2020 - Colistion detection
05/05/2020 - load map By .txt file
*/
#define _CRT_SECURE_NO_WARNINGS


#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "Components.h"
#include <vector>
#include <stdio.h>
#include <string>


class Map
{
public:

	Map();
	~Map();

	static Map* MainMap;

	void LoadMap(const char* level);

	void DrawMap();

	void update();

	std::vector<SDL_Rect> way;

	bool DetectColisionPos(int inp_x1, int inp_y1, int inp_x2, int inp_y2);

	bool DetectColision(Position inp_pos, SDL_Rect inp_size);


protected:


	SDL_Rect src;
	SDL_Rect dest;
	SDL_Rect MapLimits;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int TileSize = 32;

	int map[20][25];

	enum Tile
	{
		waterT, grassT, dirtT
	};

};

