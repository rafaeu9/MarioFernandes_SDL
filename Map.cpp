#include "Map.h"

Map* Map::MainMap = nullptr;

Map::Map()
{
	MainMap = this;

	//Difrent tips of tiles
	Brick = TextureManager::LoadBMPTexture("assets/Brick.bmp");
	Wall = TextureManager::LoadBMPTexture("assets/Wall.bmp");
	Space = TextureManager::LoadBMPTexture("assets/Space.bmp");

	//Load map Structure
	/*LoadMap("Level1");*/
	/*LoadLevel(1);*/

	//Define size of the tile
	src.x = src.y = 0;
	dest.x = dest.y = 0;
	src.w = dest.w = TileSize;
	src.h = dest.h = TileSize;

}

Map::~Map()
{
}

//Load Map
void Map::LoadMap(const char* level)
{
	
	
	FILE* fp = fopen("data/Levels.txt", "r");



	if (!fp) {
		std::perror("data/Levels.txt failed to open\n");
	}
	else {
		std::printf("data/Levels.txt successfully open\n");
	}


	while (true) {

		char type[256];

		if (fp)
			 fscanf(fp, "%s", &type);
		else
			std::printf("data/Levels.txt problem\n");

		if (strstr(level, type) != 0)
		{

			fscanf_s(fp, "%c");

			std::printf("Level 1 Loading\n");

			for (int row = 0; row < 20; row++)
			{
				for (int column = 0; column < 25; column++)
				{
					char a;
					
					fscanf_s(fp, "%c",&a);
					if(a-'0' == 0 || a - '0' == 1 || a - '0' == 2)
					{
						if (a - '0' == 2)
							numbBlocks++;

						std::printf("%c",a);
					map[row][column] = a-'0';
					}
				}
				fscanf_s(fp, "%c");
				std::printf("\n");
			}

			fclose(fp);

			break;
		}
	}

	


}

void Map::DrawMap()
{
	//Draw Map Tile By Tile
	Tile type;
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = Tile (map[row][column]);

			dest.x = column * TileSize;
			dest.y = row * TileSize;

			switch (type)
			{
			case waterT:
				TextureManager::Draw(Space, dest);				
				break;				
			case grassT:
				TextureManager::Draw(Wall, dest);				
				break;
			case dirtT:
				TextureManager::Draw(Brick, dest);				
				break;
			default:
				break;
			}
		}
	}
}

void Map::update()
{
	
}

bool Map::DetectColision(Position inp_pos, SDL_Rect inp_size)
{
	int x = inp_pos.x / TileSize;
	int y = inp_pos.y / TileSize;
	int w = (inp_pos.x + inp_size.w) / TileSize;
	int h = (inp_pos.y + inp_size.h) / TileSize;

	if (map[y][x] == 1 || map[y][w] == 1 || map[h][w] == 1 || map[h][x] == 1 || 
		map[y][x] == 2 || map[y][w] == 2 || map[h][w] == 2 || map[h][x] == 2)
		return true;
	
	for (int i = x; i < w; i++)
	{
		if (map[y][i] == 1)
			return true;
		else if (map[h][i] == 1)
			return true;
	}

	for (int i = y; i < h; i++)
	{
		if (map[i][x] == 1)
			return true;
		else if (map[i][w] == 1)
			return true;
	}
		return false;

}

void Map::DetectBlock(int inp_x, int inp_y)
{	
	map[inp_y][inp_x] = 0;

	numbBlocks--;

	if(numbBlocks <=0)
	Aplication::isRunning = false;

}

void Map::DetectPos(int inp_x, int inp_y)
{
	if (map[inp_y][inp_x] == 2)
		DetectBlock(inp_x, inp_y);
}

bool Map::DetectColisionPos(int inp_x1, int inp_y1 , int inp_x2, int inp_y2)
{
	bool check = false;

	inp_x1 /= TileSize;
	inp_y1 /= TileSize;

	
	inp_x2 /= TileSize;
	inp_y2 /= TileSize;

	for (int i = inp_x1; i <= inp_x2; i++)
	{
		for (int o = inp_y1; o <= inp_y2; o++)
		{
			
			/*printf("Check\n");*/
			if (map[o][i] == 1)
			{
				return true;
			}
			else if (map[o][i] == 2)
			{
				DetectBlock(i,o);

				check = true;
			}
		}
	}
		
	
		return check;

}
