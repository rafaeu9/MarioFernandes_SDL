#include "Controller.h"


Controller::Controller(SDL_Joystick* tempjoy, int inpID)
{
	joy = tempjoy;
	ID = inpID;

	gamecontroller = SDL_GameControllerOpen(ID);

	for (int i = 0; i < (int)m_ButtonPressed[INVALID]; i++)
	{
		m_ButtonPressed[i] = false;
	}


}

bool Controller::GetButton(Input Key)
{
	return m_ButtonPressed[Key];

}
