#include "Collision.h"

///Create a collision with a personalized size
Collision::Collision(int Inp_h, int Inp_w)
{
	Rect.h = Inp_h;
	Rect.w = Inp_w;
}

///Adapte the collision size to the sprite size
Collision::Collision(const char* path)
{
	//Get dimensions of the image
	TextureManager::LoadBMPTexture(path, &Rect);
	pos = nullptr;
}

void Collision::init()
{
	pos = &entity->getComponent<Position>();

	Aplication::collisionManger->Add(entity);
}

void Collision::update()
{
	///Update collider pos
	Rect.x = pos->x;
	Rect.y = pos->y;

	Square();

}

void Collision::draw()
{
	///Draw Collider Box
	/*SDL_RenderDrawRect(Game::renderer, &Rect);*/

}

void Collision::Square()
{

}
