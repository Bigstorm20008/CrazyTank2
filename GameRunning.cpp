#include "GameRunning.h"


GameRunning::GameRunning(ConsoleGame& game)
{
	m_pGame = &game;
}


GameRunning::~GameRunning()
{
}

void GameRunning::update()
{

}

void GameRunning::render()
{
	system("cls");
	static_cast<CrazyTank*>(m_pGame)->printBattleField();
}
