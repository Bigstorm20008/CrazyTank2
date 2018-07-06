#pragma once

#include "ConsoleGame.h"
#include "CrazyTankInput.h"
#include "MenuState.h"
#include "CrazyTankInput.h"
#include "StrongHoldCreator.h"



class CrazyTank :
	public ConsoleGame
{
public:
	explicit CrazyTank();
	virtual ~CrazyTank();

	
	void init()override;

private:
	bool initStronghold();
	void initWalls(const int& wallAmount);
};

