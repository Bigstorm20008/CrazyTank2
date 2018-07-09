#pragma once

#include "Point.h"
#include "Direction.h"

//class BattleField;
#include "ConsoleGame.h"

class Entity
{
public:
	Entity(const Point& position, const wchar_t& entityPresent, const unsigned int& durability);
	virtual ~Entity();

	virtual void doLogic(ConsoleGame& game) = 0;
	
	void decreaseHealth();
	const Point& getPosition()const;
	const wchar_t& getPresents()const;

	
protected:
	Point m_currentPosition;
	wchar_t m_presents;
	int m_durability;
private:
	
};


