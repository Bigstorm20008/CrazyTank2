#pragma once

#include "RandomEngine.h"

//class EnemyTankCreator;
#include "BattleField.h"

class BattleFieldHelpers
{
public:
	friend class EnemyTankCreator;
	
	~BattleFieldHelpers();

	Point getRandomFreePoint()const;
	bool isFreePoint(const Point& point)const;
	bool isValidPoint(const Point& point)const;
	const wchar_t& getValueInPosition(const Point& point)const;
private:
	explicit BattleFieldHelpers(const BattleField& battlefield);

	Point generatePoint()const;

	BattleField m_battleField;
	
};

