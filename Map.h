/* Change Log
26/03/2020 - Load map Texture, Create map Based on Array and draw on screen
*/

#pragma once
#include "SDL.h"
#include "TextureManager.h"
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


protected:

	SDL_Rect src;
	SDL_Rect dest;
	SDL_Rect MapLimits;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

	enum Tile
	{
		waterT, grassT, dirtT
	};

};

