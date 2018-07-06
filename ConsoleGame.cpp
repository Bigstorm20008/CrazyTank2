#include "ConsoleGame.h"


ConsoleGame::ConsoleGame()
{
	m_isRunning = true;
	m_pInput = nullptr;
	m_pCurrentGameState = nullptr;
}


ConsoleGame::~ConsoleGame()
{
	
}


int ConsoleGame::run()
{
	if ((!m_pInput) || (!m_pCurrentGameState))
	{
		std::cout << "Initialize game!!!" << std::endl;
		return 0;
	}

	//Hide cursor in console window
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);


	wchar_t userInput = {};   //variable for save user input
	
	//start game loop
	while (m_isRunning)
	{
		while (!_kbhit())
		{
			m_pCurrentGameState->update();
			m_pCurrentGameState->render();
		}

		//get user input
		userInput = _getch();

		if ((userInput == 'q') || (userInput == 'Q'))
		{
			m_isRunning = false;
			break;
		}
		else
		{
			//process user input
			const Command* command = m_pInput->messageHandler(userInput);
			if (command)
			{
				command->execute(*this);
			}
		}
	}

	return 0;
}



void ConsoleGame::setNewState(GameState* pState)
{
	if (typeid(*pState) == typeid(*m_pCurrentGameState))
	{
		delete pState;
		pState = nullptr;
		return;
	}
	else if (m_pCurrentGameState)
	{
		delete m_pCurrentGameState;
		m_pCurrentGameState = nullptr;
	}
	m_pCurrentGameState = pState;
}

void ConsoleGame::printBattleField()const
{
	m_battleField.print();
}
