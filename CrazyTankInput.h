#pragma once


#include "Input.h"
#include "StartGame.h"
#include "MoveForward.h"
#include "MoveBack.h"
#include "MoveLeft.h"
#include "MoveRight.h"
#include "Fire.h"


class CrazyTankInput :
	public Input
{
public:
	friend class CrazyTank;
	
	virtual ~CrazyTankInput();

	const Command* const messageHandler(wchar_t& userInput)override;

private:
	Command* m_pCommand;
	explicit CrazyTankInput();
};

