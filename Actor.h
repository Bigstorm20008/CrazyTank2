#pragma once

#include "Action.h"
#include "Point.h"
#include "Direction.h"

class Actor
{
public:
	explicit Actor(const Point& actorPosition, const Direction::Directions& actorDirection, const wchar_t& actorPresent, const int& actorDurability);
	virtual ~Actor();

	virtual void doAction(const Action::Actions& action) = 0;

protected:
	Point m_currentPosition;
	Direction::Directions m_currentDirection;
	wchar_t m_actorPresent;
	int m_currentDurability;	
};

