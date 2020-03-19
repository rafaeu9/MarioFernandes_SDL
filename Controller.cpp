#include "Controller.h"


Controller::Controller(SDL_Joystick* tempjoy, int inpID)
{
	joy = tempjoy;
	ID = inpID;

	gamecontroller = SDL_GameControllerOpen(ID);
}

Input Controller::GetButton()
{
	SDL_GameControllerGetButton(gamecontroller, button);

	switch (event.cbutton.button)
	{
	case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_A:
		input = Input::A;
		break;
	case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_B:
		input = Input::B;
		break;
	case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_Y:
		input = Input::Y;
		break;
	case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_X:
		input = Input::X;
		break;
	case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_DOWN:
		input = Input::DOWN_ARROW;
		break;
	case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
		input = Input::RIGHT_ARROW;
		break;
	case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_UP:
		input = Input::UP_ARROW;
		break;
	case SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_LEFT:
		input = Input::LEFT_ARROW;
		std::cout << "left" << std::endl;
		break;
	default:
		input = Input::INVALID;
		std::cout << "invalid" << std::endl;
		break;
	}

	

	return input;
}
