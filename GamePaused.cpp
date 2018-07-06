#include "GamePaused.h"


GamePaused::GamePaused()
{
	m_isVisible = false;
}


GamePaused::~GamePaused()
{
}

void GamePaused::update()
{

}

void GamePaused::render()
{
	if (!m_isVisible)
	{
		system("cls");
		std::cout << "Game paused" << std::endl;
		m_isVisible = true;
	}
}
