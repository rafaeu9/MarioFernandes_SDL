#include <iostream>
#include "Aplication.h"
#include "SDL.h"

#undef main

int main(int argc, char arg[])
{
	Aplication* App = new Aplication();

	App->Init("AE1", 50, 50, 1366, 768, false);    

	getchar();

	return 0;
}