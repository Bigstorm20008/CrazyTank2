#pragma once


#include "Input.h"
#include "StartGame.h"
#include "MoveForward.h"


class CrazyTankInput :
	public Input
{
public:
	explicit CrazyTankInput();
	virtual ~CrazyTankInput();

	const Command* const messageHandler(const wchar_t& userInput)override;
private:
	Command* m_pCommand;
};

