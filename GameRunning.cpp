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
	for (auto& entity : m_pGame->m_entities)
	{
		entity->doLogic(*m_pGame);
	}

	for (auto& entity : m_pGame->m_entitiesToDelete)
	{
		Point entityPosition = entity->getPosition();
		m_pGame->m_backBuffer.setValueInPosition(entityPosition.xPosition, entityPosition.yPosition, emptySpace);
		auto pos = std::find(m_pGame->m_entities.begin(), m_pGame->m_entities.end(), entity);	
		m_pGame->m_entities.erase(pos);
		delete entity;
		entity = nullptr;
		
		
	}
	m_pGame->m_entitiesToDelete.clear();
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
