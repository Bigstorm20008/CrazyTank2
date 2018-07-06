#pragma once

#include "Point.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void doLogic() = 0;

	const Point& getPosition()const;
	const wchar_t& getPresents()const;
protected:
	Point m_currentPosition;
	wchar_t m_presents;
	int m_durability;
};

