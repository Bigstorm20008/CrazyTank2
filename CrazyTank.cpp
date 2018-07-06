#include "CrazyTank.h"


CrazyTank::CrazyTank() : ConsoleGame()
{
}


CrazyTank::~CrazyTank()
{
	if (m_pCurrentGameState)
	{
		delete m_pCurrentGameState;
		m_pCurrentGameState = nullptr;
	}

	if (m_pInput)
	{
		delete m_pInput;
		m_pInput = nullptr;
	}
}

void CrazyTank::init()
{
	m_pCurrentGameState = new MenuState;
	m_pInput = new CrazyTankInput;

	m_battleFild.init();
}

void CrazyTank::printBattleField()const
{
	m_battleFild.print();
}



