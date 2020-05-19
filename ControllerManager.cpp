#include "ControllerManager.h"

ControllerManager* ControllerManager::controllermnager = nullptr;

ControllerManager::ControllerManager()
{

	controllermnager = this;

	// Initialize the joystick subsystem
	SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	if(joyTotal == 0)
	do
	{		
		/*SDL_Delay(1000);*/

		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
		joyTotal = SDL_NumJoysticks();
		if (joyTotal == 0)
				std::printf("Couldn't detect a controller\n");

	} while (joyTotal == 0);
		

		// Check for joystick
		if (joyTotal > 0) {

			for (int i = 0; i < joyTotal; i++)
			{

				// Open joystick
				Controller* tempJoy = new Controller(SDL_JoystickOpen(i), i);

				//Information of the controllers
				if (tempJoy->joy) {
					std::printf("Opened Joystick %d\n", i);
					std::printf("Name: %s\n", SDL_JoystickNameForIndex(i));
					std::printf("Number of Axes: %d\n", SDL_JoystickNumAxes(tempJoy->joy));
					std::printf("Number of Buttons: %d\n", SDL_JoystickNumButtons(tempJoy->joy));
					std::printf("Number of Balls: %d\n", SDL_JoystickNumBalls(tempJoy->joy));

					controllers.push_back(tempJoy);
				}
				else {
					std::printf("Couldn't open Joystick %d\n", i);
				}
			}
		
		}

		
	
}

ControllerManager::~ControllerManager()
{
	for (int i = 0; i < controllers.size(); i++)
	{
		// Close if opened
		if (SDL_JoystickGetAttached(controllers[i]->joy)) {
			SDL_JoystickClose(controllers[i]->joy);
		}
	}
}

void ControllerManager::Update()
{	


	while (SDL_PollEvent(ev) != NULL)
	{		

		if (ev->type == SDL_CONTROLLERBUTTONDOWN)
		{
			int ID = ev->cbutton.which;
			/*SDL_GameControllerGetButton(gamecontroller, button);*/

			switch (ev->cbutton.button)
			{
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_A:
				controllers[ID]->m_ButtonPressed[A] = true;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_B:
				controllers[ID]->m_ButtonPressed[B] = true;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_Y:
				controllers[ID]->m_ButtonPressed[Y] = true;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_X:
				controllers[ID]->m_ButtonPressed[X] = true;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_DOWN:
				controllers[ID]->m_ButtonPressed[DOWN_ARROW] = true;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
				controllers[ID]->m_ButtonPressed[RIGHT_ARROW] = true;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_UP:
				controllers[ID]->m_ButtonPressed[UP_ARROW] = true;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_LEFT:
				controllers[ID]->m_ButtonPressed[LEFT_ARROW] = true;
				break;
			default:
				break;
			}
		}
		else if (ev->type == SDL_CONTROLLERBUTTONUP)
		{

			int ID = ev->cbutton.which;

			switch (ev->cbutton.button)
			{
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_A:
				controllers[ID]->m_ButtonPressed[A] = false;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_B:
				controllers[ID]->m_ButtonPressed[B] = false;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_Y:
				controllers[ID]->m_ButtonPressed[Y] = false;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_X:
				controllers[ID]->m_ButtonPressed[X] = false;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_DOWN:
				controllers[ID]->m_ButtonPressed[DOWN_ARROW] = false;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
				controllers[ID]->m_ButtonPressed[RIGHT_ARROW] = false;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_UP:
				controllers[ID]->m_ButtonPressed[UP_ARROW] = false;
				break;
			case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_LEFT:
				controllers[ID]->m_ButtonPressed[LEFT_ARROW] = false;
				break;
			default:
				break;
			}
		}
	}
}
