#pragma once
#include "Components.h"

class Position :
	public Component
{
public:
	int x, y;

	Position();
	Position(int inp_x, int inp_y);
};

