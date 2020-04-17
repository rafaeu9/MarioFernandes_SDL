#include "Movement.h"

Movement::Movement(Map* Inp_map, Controller* controller_ID)
{
	controller = controller_ID;
	map = Inp_map;
	
}

void Movement::update()
{
	if (controller)
	{
		LastPos = entity->getComponent<Position>();

		if (controller->GetButton(UP_ARROW))
			Up();
		else if(controller->GetButton(DOWN_ARROW))
			Down();

		if (controller->GetButton(RIGHT_ARROW))
			Right();
		else if (controller->GetButton(LEFT_ARROW))
			Left();
		
		if (map->DetectColision(entity->getComponent<Position>(), entity->getComponent<Sprite>().destRect))
		{


			entity->getComponent<Position>() = LastPos;
		}

	}
}

void Movement::Up()
{
	printf("Up");
	entity->getComponent<Position>().y -= Speed;	
}

void Movement::Down()
{
	printf("Down");
	entity->getComponent<Position>().y += Speed;
}

void Movement::Left()
{
	printf("Left");
	entity->getComponent<Position>().x -= Speed;
}

void Movement::Right()
{
	printf("Right");
	entity->getComponent<Position>().x += Speed;
}


