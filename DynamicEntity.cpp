#include "DynamicEntity.h"


DynamicEntity::DynamicEntity()
{
}


DynamicEntity::~DynamicEntity()
{
}

void DynamicEntity::goToNextPositon(ConsoleGame& game)
{
	Point nextPoint = computeNextPosition();

	if (nextPoint == m_currentPosition)
	{
		return;
	}

	if (!game.m_backBuffer.isValidPoint(nextPoint))
	{
		game.m_backBuffer.setValueInPosition(m_currentPosition.xPosition, m_currentPosition.yPosition, emptySpace);
		game.m_entitiesToDelete.push_back(this);
		return;
	}

	if (!game.m_backBuffer.isFreePoint(nextPoint))
	{
		procesCollision(nextPoint,game);
	}
	else
	{
		game.m_backBuffer.setValueInPosition(nextPoint.xPosition, nextPoint.yPosition, m_presents);
		game.m_backBuffer.setValueInPosition(m_currentPosition.xPosition, m_currentPosition.yPosition, emptySpace);
		m_currentPosition = nextPoint;
	}
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