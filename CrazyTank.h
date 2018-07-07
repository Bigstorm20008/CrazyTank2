#pragma once

#include "ConsoleGame.h"
#include "CrazyTankInput.h"
#include "MenuState.h"
#include "CrazyTankInput.h"
#include "StrongHoldCreator.h"
#include "PlayerTank.h"



class CrazyTank :
	public ConsoleGame
{
public:
	explicit CrazyTank();
	virtual ~CrazyTank();

	
	void init()override;

private:
	bool initStronghold(const int& width, const int& height, const wchar_t allStrongHoldBlockPresents[]);
	void initWalls(const wchar_t allWallBlockPresents[],const int& wallAmount);
	void initPlayerTank(const Point& tankPosition, const Direction::Directions& tankDirection, const wchar_t& tankPresent, const int& tankDurability);
};

