#include "Map.h"




// Map structure
int lvl[20][25] = {

	{ 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 }

};



Map::Map()
{
	//Difrent tips of tiles
	dirt = TextureManager::LoadBMPTexture("assets/dirt.bmp");
	grass = TextureManager::LoadBMPTexture("assets/grass.bmp");
	water = TextureManager::LoadBMPTexture("assets/water.bmp");

	//Load map Structure
	LoadMap("Level2");

	//Define size of the tile
	src.x = src.y = 0;
	dest.x = dest.y = 0;
	src.w = dest.w = TileSize;
	src.h = dest.h = TileSize;


	////Define Map colision
	//Tile type;
	//for (int row = 0; row < 20; row++)
	//{
	//	for (int column = 0; column < 25; column++)
	//	{
	//		type = Tile(map[row][column]);

	//		dest.x = column * 32;
	//		dest.y = row * 32;

	//		switch (type)
	//		{
	//		case waterT:
	//			way.push_back(dest);
	//			break;
	//		case dirtT:
	//			way.push_back(dest);
	//			break;
	//		case grassT:
	//		default:
	//			break;
	//		}
	//	}
	//}

	////Define Map Borders
	//MapLimits.x = 1 * 32;
	//MapLimits.y = 1 * 32;
	//MapLimits.w = 25 * 32 + 32;
	//MapLimits.h = 17 * 32 + 32;
}

//Load Map
void Map::LoadMap(const char* level)
{
	
	
	FILE* fp = fopen("data/Levels.txt", "r");



	if (!fp) {
		std::perror("data/Levels.txt failed to open\n");
	}
	else {
		printf("data/Levels.txt successfully open\n");
	}


	while (true) {

		char type[256];

		if (fp)
			 fscanf(fp, "%s", &type);
		else
			printf("data/Levels.txt problem\n");

		if (strstr(level, type) != 0)
		{

			fscanf_s(fp, "%c");

			printf("Level 1 Loading\n");

			for (int row = 0; row < 20; row++)
			{
				for (int column = 0; column < 25; column++)
				{
					char a;
					
					fscanf_s(fp, "%c",&a);
					if(a-'0' == 0 || a - '0' == 1 || a - '0' == 2)
					{
					printf("%c",a);
					map[row][column] = a-'0';
					}
				}
				fscanf_s(fp, "%c");
				printf("\n");
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
				TextureManager::Draw(water, dest);				
				break;				
			case grassT:
				TextureManager::Draw(grass, dest);				
				break;
			case dirtT:
				TextureManager::Draw(dirt, dest);				
				break;
			default:
				break;
			}
		}
	}
}

void Map::update()
{
	////Detect if ther is any Colision inside the map
	//for (auto& i : way)	
	//	for (auto& e : Game::collisionManger->Colliders)
	//		if (e->hasComponent<RigidBody>())
	//		{
	//			if (CollisionManager::Detect(e->getComponent<Collision>().Rect, i))
	//			{
	//				e->getComponent<RigidBody>().RevertPos();
	//				break;
	//			}
	//		}		
	////Detect if ther is any Colision on the borders
	//for (auto& i : Game::collisionManger->Colliders) if (i->hasComponent<RigidBody>())
	//{
	//	if (!CollisionManager::Detect(i->getComponent<Collision>().Rect, MapLimits))
	//		i->getComponent<RigidBody>().RevertPos();
	//}
}

bool Map::DetectColision(Position inp_pos, SDL_Rect inp_size)
{
	int x = inp_pos.x / TileSize;
	int y = inp_pos.y / TileSize;
	int w = (inp_pos.x + inp_size.w) / TileSize;
	int h = (inp_pos.y + inp_size.h) / TileSize;

	if (map[y][x] == 2 || map[y][w] == 2 || map[h][w] == 2 || map[h][x] == 2)
		return true;
	else
		return false;

}
