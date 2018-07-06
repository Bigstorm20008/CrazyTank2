#pragma once

#include "ConsoleGame.h"
#include "CrazyTankInput.h"
#include "MenuState.h"
#include "CrazyTankInput.h"



class CrazyTank :
	public ConsoleGame
{
public:
	explicit CrazyTank();
	virtual ~CrazyTank();

	
	void init()override;

	using ConsoleGame::run;

private:
	using ConsoleGame::printBattleField;
	using ConsoleGame::setNewState;
};

