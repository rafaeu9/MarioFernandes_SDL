#include "Ball.h"

Ball::Ball(Entity* Inp_Player)
{

	Player = Inp_Player;

	XSpeed = 0;
	YSpeed = 0;	
}

Ball::~Ball()
{
}

void Ball::update()
{

	if (YSpeed == 0)
	{
		entity->getComponent<Position>().y = 480;
		entity->getComponent<Position>().x = Player->getComponent<Position>().x + Player->getComponent<Sprite>().destRect.w /2 - 16;
		if (ControllerManager::controllermnager->controllers[0]->m_ButtonPressed[A])
		{
			YSpeed = -1;

			if ((int)(rand() % 100 + 1) <= 50)
				XSpeed = -2;
			else
				XSpeed = 2;
		}
	}
	else
	{
		Bounce();
		PlayerDetection();
		Move();
	}

}

void Ball::Move()
{
	entity->getComponent<Position>().x += XSpeed;
	entity->getComponent<Position>().y += YSpeed;
}

void Ball::Bounce()
{	
	if (Map::MainMap->DetectColision(entity->getComponent<Position>(), entity->getComponent<Sprite>().destRect))
	{
		entity->getComponent<Position>().x -= XSpeed;
		entity->getComponent<Position>().y -= YSpeed;

		if (Map::MainMap->DetectColisionPos(entity->getComponent<Position>().x, entity->getComponent<Position>().y - 2,
		entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w, entity->getComponent<Position>().y - 2))
		{			
			YSpeed *= -1;
		}
		else if (Map::MainMap->DetectColisionPos(entity->getComponent<Position>().x, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h + 2, 
		entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h + 2))
		{			
			YSpeed *= -1;

			if((entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h) > Player->getComponent<Position>().y)
			Aplication::isRunning = false;
		}
		else if(Map::MainMap->DetectColisionPos(entity->getComponent<Position>().x - 2, entity->getComponent<Position>().y,
		entity->getComponent<Position>().x - 2, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h))
		{			
			XSpeed *= -1;
		}
		else if (Map::MainMap->DetectColisionPos(entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w + 2, entity->getComponent<Position>().y,
		entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w + 2, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h))
		{			
			XSpeed *= -1;
		}
		else
		{
			XSpeed *= -1;
			YSpeed *= -1;

			Map::MainMap->DetectPos(entity->getComponent<Position>().x - 2, entity->getComponent<Position>().y - 2);
			Map::MainMap->DetectPos(entity->getComponent<Position>().x - 2, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h + 2);
			Map::MainMap->DetectPos(entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w + 2, entity->getComponent<Position>().y - 2);
			Map::MainMap->DetectPos(entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w + 2, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h + 2);
		}
	}	
}

void Ball::PlayerDetection()
{
	if(!((entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h) > Player->getComponent<Position>().y) && YSpeed >0)
	if (Player->getComponent<Position>().x + Player->getComponent<Sprite>().destRect.w >= entity->getComponent<Position>().x &&
		entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w >= Player->getComponent<Position>().x &&
		Player->getComponent<Position>().y + Player->getComponent<Sprite>().destRect.h >= entity->getComponent<Position>().y &&
		entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h >= Player->getComponent<Position>().y)
	{
		YSpeed *= -1;
	}



	//for (int i = Player->getComponent<Position>().x; i <= Player->getComponent<Position>().x + Player->getComponent<Sprite>().destRect.w; i++)
	//{
	//	for (int u = entity->getComponent<Position>().x; u <= entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w; u++)
	//	{
	//		if ((i, Player->getComponent<Position>().y) == (u, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h))
	//		{					
	//			YSpeed *= -1;
	//			break;
	//		}
	//	}
	//}	
}
