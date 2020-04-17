/* Change Log
26/03/2020 - Load map Texture, Create map Based on Array and draw on screen
17/04/2020 - Colistion detection
*/

#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "Components.h"
#include <vector>


class Map
{
public:

	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

	void update();

	std::vector<SDL_Rect> way;

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

