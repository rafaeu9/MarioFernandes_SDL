/*Change Log
7/05/2020 - Ball creation, movemnt and start of collision detection
8/05/2020 - Collision detection in any point and bouncing
8/05/2020 - Player detection in any point and bouncing
18/05/2020 - Ball ground detection
*/


#pragma once
#include "ECS.h"
#include "Position.h"
#include "Map.h"

class Ball :
	public Component
{
public:
	Ball(Entity* Inp_Player);
	~Ball();

	void update();

	
	
protected:

	int XSpeed, YSpeed;

	Entity* Player;

	void Move();
	void Bounce();
	void PlayerDetection();
};

