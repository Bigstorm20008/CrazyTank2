#pragma once

#include<random>
#include<ctime>

class EnemyTank;
#include"EnemyTank.h"
#include "BattleFieldHelpers.h"

class EnemyTankCreator
{
public:
	friend class CrazyTank;

	~EnemyTankCreator();

	EnemyTank* createEnemyTank(const BattleFieldHelpers& battleFieldHelper);
private:
	explicit EnemyTankCreator(const wchar_t& enemyTankPresent, const unsigned int& enemyTankDurability, const unsigned int offsetBetweenTanks);

	wchar_t m_tankPresent;
	unsigned int m_Durability;
	unsigned int m_offsetBetweenTanks;

	bool checkAreaArroundPoint(const Point& point, const BattleFieldHelpers& battleFieldHelpers)const;
};

