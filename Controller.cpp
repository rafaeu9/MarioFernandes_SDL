#include "Controller.h"


Controller::Controller(SDL_Joystick* tempjoy, int inpID)
{
	joy = tempjoy;
	ID = inpID;

	gamecontroller = SDL_GameControllerOpen(ID);
}

bool Controller::GetButton(Input Key)
{
	return m_ButtonPressed[Key];

}
