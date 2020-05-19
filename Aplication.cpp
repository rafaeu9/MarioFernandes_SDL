#include "Aplication.h"

SDL_Renderer* Aplication::renderer = nullptr;
//Controller* Aplication::controller = nullptr;

bool Aplication::isRunning = false;

Aplication::Aplication()
{
}

void Aplication::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

#pragma region Create Window

	window = nullptr;

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Check if SDL is inicialized
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		//create the window
		window = SDL_CreateWindow(
			title,				//title
			xpos,				//initial x position
			ypos,				//initial y position
			width,				//width, in pixels
			height,				//height, in pixels
			flags				//window behaviour flags (ignorw for now)
		);

		if (!window)
		{
			printf("WINDOW initialisation failed: %s\n", SDL_GetError());
			printf("Press any key to continued\n");
			getchar();
			return;
		}

		renderer = SDL_CreateRenderer(
			window,				//link the renderer to our newly created win
			-1,					//index rendering driver (ignore for now)
			0					//renderer behaviour flags (ignore for now)
		);

		if (!renderer)
		{
			printf("RENDERER initialisation failed: %s\n", SDL_GetError());
			printf("Press any key to continued\n");
			getchar();
			return;
		}

		if (renderer)
		{
			SDL_SetRenderDrawColor(
				renderer,		//our target renderer
				255,			//r
				255,			//g
				255,			//b
				255				//alpha
			);
		}


		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
#pragma endregion Create Window

	controllerManager = new ControllerManager();

	map = new Map();

	if (controllerManager && map && isRunning)
		isRunning = true;
	else
		isRunning = false;
		

	if (isRunning)
		Running();
	else
		End();
}


void Aplication::CreateEnteties()
{

	//Creating the player
	Entity& Player(manager.addEntity());
	Player.addComponent<Position>(336,512);
	Player.addComponent<Sprite>("assets/Platform.bmp");
	Player.getComponent<Sprite>().destRect.w = 128;
	Player.getComponent<Sprite>().destRect.h = 32;
	Player.addComponent<Movement>(map, controllerManager->controllers[0]).Speed = 5;

	//Creating the Ball
	Entity& BouncingBall(manager.addEntity());	
	BouncingBall.addComponent<Position>();
	BouncingBall.addComponent<Sprite>("assets/ball.bmp");
	BouncingBall.getComponent<Sprite>().destRect.w = 32;
	BouncingBall.getComponent<Sprite>().destRect.h = 32;
	BouncingBall.addComponent<Ball>(Player.getComponent<Position>().entity);
}


void Aplication::Running()
{
	map->LoadMap("Level2");

	CreateEnteties();


	//Target Frame rate
	const int FPS = 60;
	//Max time between frames
	const int frameDelay = 1000 / FPS;

	int FrameCount = 0;
	Uint32 CountSec = 0;

	Uint32 frameStart;
	int frameTime;

	while (isRunning)
	{
		//Current game time
		frameStart = SDL_GetTicks();

		Update();
		Draw();

		//How long the cicle took
		frameTime = SDL_GetTicks() - frameStart;

		//check if need to Delay
		if (frameDelay > frameTime)
		{
			//How mush time will delay
			SDL_Delay(frameDelay - frameTime);
		}

		//Add frame count
		FrameCount++;

		//Detect how much time take to update game
		frameTime = SDL_GetTicks() - frameStart;

		//Store time
		CountSec += frameTime;

		//if pass 1 second display frame rate
		if (CountSec >= 1000)
		{
			CountSec = 0;

			std::cout << FrameCount << " FPS" << endl;

			FrameCount = 0;
		}

		
	}

	End();
}


void Aplication::Update()
{	

	controllerManager->Update();

	manager.update();

	if (controllerManager->controllers[0]->GetButton(Input::X))
		isRunning = false;

	SDL_PollEvent(controllerManager->ev);
	switch (controllerManager->ev->type)
	{
		//detect if the X of the window was pressed
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

}

void Aplication::Draw()
{
	//Redraw Map
	map->DrawMap();

	manager.draw();

	//Draw on screen
	SDL_RenderPresent(renderer);

	//Clean window
	SDL_RenderClear(renderer);


}

void Aplication::End()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("GameClean\n");
}
