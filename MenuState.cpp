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
		std::wcout << "    Game in menu" << std::endl;
		std::wcout << "Press S key for begin" << std::endl;
		std::wcout << "Press Q key for exit" << std::endl;
		std::wcout << std::endl;
		std::wcout << "    Tank controls:" << std::endl;
		std::wcout << "Use arrows key for moving" << std::endl;
		std::wcout << "Use space for fire" << std::endl;
		m_isVisible = true;
	}
}
