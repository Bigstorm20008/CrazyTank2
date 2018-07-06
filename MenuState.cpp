#include "MenuState.h"


MenuState::MenuState()
{
	m_isVisible = false;
}


MenuState::~MenuState()
{
}

void MenuState::update()
{

}

void MenuState::render()
{
	if (!m_isVisible)
	{
		system("cls");
		std::cout << "Game in menu" << std::endl;
		std::cout << "Press S key for begin" << std::endl;
		m_isVisible = true;
	}
}
