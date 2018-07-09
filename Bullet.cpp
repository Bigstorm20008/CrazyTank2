#include "Bullet.h"


Bullet::Bullet(const Point& position, const wchar_t& entityPresent, const unsigned int& durability, const Direction::Directions& direction)
	: DynamicEntity(position,entityPresent,durability,direction)
{
}


Bullet::~Bullet()
{
}

void Bullet::goToNextPositon(ConsoleGame& game)
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
		procesCollision(nextPoint, game);
	}
	else
	{
		game.m_backBuffer.setValueInPosition(nextPoint.xPosition, nextPoint.yPosition, m_presents);
		game.m_backBuffer.setValueInPosition(m_currentPosition.xPosition, m_currentPosition.yPosition, emptySpace);
		m_currentPosition = nextPoint;
	}
}


