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

const Command* const CrazyTankInput::messageHandler(const wchar_t& userInput)
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
		default:
		{
			return nullptr;
		}
	}
}
