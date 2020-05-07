#include "Ball.h"

Ball::Ball()
{

	XSpeed = 1;
	YSpeed = 1;
}

Ball::~Ball()
{
}

void Ball::update()
{
	Bounce();
	Move();

	
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
		printf("Detect\n");

		//entity->getComponent<Position>().x -= XSpeed;
		//entity->getComponent<Position>().y -= YSpeed;

		if (Map::MainMap->DetectColisionPos(entity->getComponent<Position>().x, entity->getComponent<Position>().y - 2,
		entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w, entity->getComponent<Position>().y - 2))
		{
			printf("Up");
			YSpeed *= -1;
		}
		else if (Map::MainMap->DetectColisionPos(entity->getComponent<Position>().x, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h + 2, 
		entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h + 2))
		{
			printf("Down");
			YSpeed *= -1;
		}
		else
		if(Map::MainMap->DetectColisionPos(entity->getComponent<Position>().x - 2, entity->getComponent<Position>().y,
		entity->getComponent<Position>().x - 2, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h))
		{
			printf("Left");
			XSpeed *= -1;
		}
		else if (Map::MainMap->DetectColisionPos(entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w + 2, entity->getComponent<Position>().y,
		entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w + 2, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h))
		{
			printf("Right");
			XSpeed *= -1;
		}

	

		/*if (Map::MainMap->DetectColisionPos(entity->getComponent<Position>().x, entity->getComponent<Position>().y,
			entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w, entity->getComponent<Position>().y))
		{
			printf("Up");
			YSpeed *= -1;
		}
		else if (Map::MainMap->DetectColisionPos(entity->getComponent<Position>().x, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h,
			entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h))
		{
			printf("Down");
			YSpeed *= -1;
		}

		if (Map::MainMap->DetectColisionPos(entity->getComponent<Position>().x, entity->getComponent<Position>().y,
			entity->getComponent<Position>().x, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h))
		{
			printf("Left");
			XSpeed *= -1;
		}
		else if (Map::MainMap->DetectColisionPos(entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w, entity->getComponent<Position>().y,
			entity->getComponent<Position>().x + entity->getComponent<Sprite>().destRect.w, entity->getComponent<Position>().y + entity->getComponent<Sprite>().destRect.h))
		{
			printf("Right");
			XSpeed *= -1;
		}*/
	}
	
	
	
}
