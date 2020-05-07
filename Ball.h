/*Change Log
7/05/2020 - Ball creation, movemnt and start of collision detection
*/


#pragma once
#include "ECS.h"
#include "Position.h"
#include "Map.h"

class Ball :
	public Component
{
public:
	Ball();
	~Ball();

	void update();

	
	
protected:

	int XSpeed, YSpeed;

	void Move();
	void Bounce();
};

