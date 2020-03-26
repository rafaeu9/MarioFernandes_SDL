#include "Aplication.h"

#undef main

int main(int argc, char arg[])
{
	Aplication* App = new Aplication();

	App->Init("AE1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1366, 768, false);

	return 0;
}