#include "DynamicEntity.h"


DynamicEntity::DynamicEntity(const Point& position, const wchar_t& entityPresent, const unsigned int& durability, const Direction::Directions& direction)
	:Entity(position, entityPresent, durability), m_direction(direction)
{
}


DynamicEntity::~DynamicEntity()
{
}

const Point DynamicEntity::computeNextPosition()const
{
	Point nextPoint = m_currentPosition;
	switch (m_direction)
	{
	case Direction::Directions::up:
	{
		--nextPoint.yPosition;
		break;
	}
	case Direction::Directions::down:
	{
		++nextPoint.yPosition;
		break;
	}
	case Direction::Directions::left:
	{
		--nextPoint.xPosition;
		break;
	}
	case Direction::Directions::right:
	{
		++nextPoint.xPosition;
		break;
	}
	default:
	{
		break;
	}
	}

	return nextPoint;
}


const Direction::Directions& DynamicEntity::getDirection()const
{
	return m_direction;
}