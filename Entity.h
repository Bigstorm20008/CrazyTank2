#pragma once

#include "Point.h"
#include "Direction.h"

//class BattleField;
#include "BattleField.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void doLogic(BattleField& backBufferField) = 0;
	

	const Point& getPosition()const;
	const wchar_t& getPresents()const;
	const Direction& getDirection()const;
protected:
	Point m_currentPosition;
	Direction m_direction;
	wchar_t m_presents;
	int m_durability;
};

