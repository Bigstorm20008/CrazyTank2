#pragma once

#include "Point.h"
#include "Direction.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void doLogic() = 0;
	

	const Point& getPosition()const;
	const wchar_t& getPresents()const;
	const Direction& getDirection()const;
protected:
	Point m_currentPosition;
	Direction m_direction;
	wchar_t m_presents;
	int m_durability;

	virtual void processCollision(const wchar_t& collision) = 0;

};

