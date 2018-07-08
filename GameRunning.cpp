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
	//m_pGame->m_backBuffer = m_pGame->m_battleField;
}

void GameRunning::render()
{
	if (!m_isVisible)
	{
		system("cls");
		m_pGame->printBattleField();
		m_isVisible = true;
	}
	else
	{
		auto& backBufferSymbols = m_pGame->m_backBuffer.getPlayField();
		auto& currentView = m_pGame->m_battleField.getPlayField();

		HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD scrn;

		for (int i = 0; i != backBufferSymbols.size(); ++i)
		{
			for (int j = 0; j != backBufferSymbols[i].size(); ++j)
			{
				if (backBufferSymbols[i][j] != currentView[i][j])
				{
					scrn.X = j;
					scrn.Y = i;
					SetConsoleCursorPosition(hOuput, scrn);
					std::wcout << backBufferSymbols[i][j];
				}
			}
		}
		currentView = backBufferSymbols;
	}	
}
