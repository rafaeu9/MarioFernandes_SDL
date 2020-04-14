#include "Movement.h"

Movement::Movement(Controller* controller_ID)
{
	controller = controller_ID;
}

void Movement::update()
{
	if (controller)
	{
		if (controller->GetButton(UP_ARROW))
			Up();
		else if(controller->GetButton(DOWN_ARROW))
			Down();

		if (controller->GetButton(RIGHT_ARROW))
			Right();
		else if (controller->GetButton(LEFT_ARROW))
			Left();
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


