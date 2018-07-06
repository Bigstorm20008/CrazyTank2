#include "GameRunning.h"


GameRunning::GameRunning(ConsoleGame& game)
{
	m_pGame = &game;
	m_isVisible = false;
}


GameRunning::~GameRunning()
{
}

void GameRunning::update()
{

}

void GameRunning::render()
{
	if (!m_isVisible)
	{
		system("cls");
		m_pGame->printBattleField();
		m_isVisible = true;
	}
}
