#include "Aplication.h"

SDL_Renderer* Aplication::renderer = nullptr;
//Controller* Aplication::controller = nullptr;

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

#pragma region Controller	

	// Initialize the joystick subsystem
	if (SDL_InitSubSystem(SDL_INIT_JOYSTICK) == 0)
	{

		joyTotal = SDL_NumJoysticks();

		// Check for joystick
		if (joyTotal > 0) {

			for (int i = 0; i < joyTotal; i++)
			{
				// Open joystick
				Controller tempJoy(SDL_JoystickOpen(i), i);			

				if (tempJoy.joy) {
					printf("Opened Joystick %d\n", i);
					printf("Name: %s\n", SDL_JoystickNameForIndex(i));
					printf("Number of Axes: %d\n", SDL_JoystickNumAxes(tempJoy.joy));
					printf("Number of Buttons: %d\n", SDL_JoystickNumButtons(tempJoy.joy));
					printf("Number of Balls: %d\n", SDL_JoystickNumBalls(tempJoy.joy));

					controllers.push_back(&tempJoy);

				}
				else {
					printf("Couldn't open Joystick %d\n", i);
				}
				// Close if opened
				if (SDL_JoystickGetAttached(joy)) {
					SDL_JoystickClose(joy);
				}
			}

		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

#pragma endregion Controller

	/*controller = new Controller();*/

	/*map = new Map();*/

	if (isRunning)
		Running();
	else
		End();
}

void Aplication::Running()
{
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

	
}

void Aplication::Update()
{	

	if (controllers[0]->GetButton() == Input::LEFT_ARROW)
		printf("Left Arrow");
	else if (controllers[0]->GetButton() == Input::X)
		isRunning = false;

}

void Aplication::Draw()
{
}

void Aplication::End()
{
}
