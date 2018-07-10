#pragma once

#include "ConsoleGame.h"
#include "CrazyTankInput.h"
#include "MenuState.h"
#include "CrazyTankInput.h"
#include "StrongHoldCreator.h"
#include "PlayerTank.h"
#include "WallCreator.h"
#include "EnemyTankCreator.h"



class CrazyTank :
	public ConsoleGame
{
public:
	friend class EnemyTank;

	explicit CrazyTank();
	virtual ~CrazyTank();

	
	void init()override;

private:
	bool initStronghold(const int& width, const int& height, const wchar_t allStrongHoldBlockPresents[]);
	void initWalls(const wchar_t allWallBlockPresents[],const int& wallAmount, const unsigned int& minWallLen, const unsigned int& maxWallLen);
	void initPlayerTank(const Point& tankPosition, const Direction::Directions& tankDirection, const wchar_t& tankPresent, const int& tankDurability);
	void initEnemyTanks(const unsigned int& tanksAmount, const wchar_t& enemyTankPresent, const unsigned int enemyTankDurability, const unsigned int offsetBetweenTanks);
};

