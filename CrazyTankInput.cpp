#include "CrazyTankInput.h"


CrazyTankInput::CrazyTankInput()
{
	m_pCommand = nullptr;
}


CrazyTankInput::~CrazyTankInput()
{
	if (m_pCommand)
	{
		delete m_pCommand;
		m_pCommand = nullptr;
	}
}

const Command* const CrazyTankInput::messageHandler(wchar_t& userInput)
{

	if (m_pCommand)
	{
		delete m_pCommand;
		m_pCommand = nullptr;
	}

	
	switch (userInput)
	{
		case 's':
		{
			m_pCommand = new StartGame;
			return m_pCommand;
		}
		case -32:
		{
			userInput = _getch();
			break;
		}
		case 77: //Right arrow
		{
			m_pCommand = new MoveRight;
			return m_pCommand;
		}
		case 75: //Left arrow
		{
			m_pCommand = new MoveLeft;
			return m_pCommand;
		}
		case 80: //Down arrow
		{
			m_pCommand = new MoveBack;
			return m_pCommand;
		}
		case 72: //Up arrow
		{
			m_pCommand = new MoveForward;
			return m_pCommand;
		}
		default:
		{
			return nullptr;
		}
	}
}
