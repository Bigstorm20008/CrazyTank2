#pragma once

#include "Entity.h"

class DynamicEntity :
	public Entity
{
public:
	explicit DynamicEntity(const Point& position, const wchar_t& entityPresent, const unsigned int& durability, const Direction::Directions& direction);
	virtual ~DynamicEntity();

	const Direction::Directions& getDirection()const;

protected:
	Direction::Directions m_direction;
	const Point computeNextPosition()const;

	virtual void procesCollision(const Point& point, ConsoleGame& game) = 0;
};

