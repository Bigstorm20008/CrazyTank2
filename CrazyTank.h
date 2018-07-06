#pragma once

#include "ConsoleGame.h"
#include "CrazyTankInput.h"
#include "MenuState.h"
#include "CrazyTankInput.h"

#include "BattleField.h"

class CrazyTank :
	public ConsoleGame
{
public:
	explicit CrazyTank();
	virtual ~CrazyTank();

	void init()override;
	void printBattleField()const;
private:
	BattleField m_battleFild;
};

