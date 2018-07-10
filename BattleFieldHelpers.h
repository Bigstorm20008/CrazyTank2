#pragma once

#include "RandomEngine.h"

//class EnemyTankCreator;
#include "BattleField.h"

class BattleFieldHelpers
{
public:
	friend class CrazyTank;
	
	~BattleFieldHelpers();

	Point getRandomFreePoint()const;
	bool isFreePoint(const Point& point)const;
	bool isValidPoint(const Point& point)const;
	const wchar_t& getValueInPosition(const Point& point)const;

	const unsigned int& getWidth()const;
	const unsigned int& getHeight()const;
private:
	explicit BattleFieldHelpers(const BattleField& battlefield);

	Point generatePoint()const;

	const BattleField* const m_battleField;
	
};

