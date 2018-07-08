#include "DynamicEntity.h"


DynamicEntity::DynamicEntity()
{
}


DynamicEntity::~DynamicEntity()
{
}

void DynamicEntity::goToNextPositon(BattleField& battlefield)
{
	Point nextPoint = computeNextPosition();

	if (nextPoint == m_currentPosition)
	{
		return;
	}

	if (!battlefield.isValidPoint(nextPoint))
	{
		return;
	}

	if (!battlefield.isFreePoint(nextPoint))
	{
		wchar_t collision = battlefield.getValueInPosition(nextPoint.xPosition, nextPoint.yPosition);
		procesCollision(collision);
	}
	else
	{
		battlefield.setValueInPosition(nextPoint.xPosition, nextPoint.yPosition, m_presents);
		battlefield.setValueInPosition(m_currentPosition.xPosition, m_currentPosition.yPosition, emptySpace);
		m_currentPosition = nextPoint;
	}
}

const Point DynamicEntity::computeNextPosition()const
{
	Point nextPoint = m_currentPosition;
	switch (m_direction.direction)
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
