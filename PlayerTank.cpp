#include "PlayerTank.h"


PlayerTank::PlayerTank(const Point& tankPosition, const Direction::Directions& tankDirection, const wchar_t& tankPresent, const int& tankDurability) 
	: Actor(tankPosition,tankDirection,tankPresent,tankDurability)
{
}


PlayerTank::~PlayerTank()
{
}

void PlayerTank::doAction(const Action::Actions& action, BattleField& playfield)
{
	switch (action)
	{
		case Action::Actions::MoveBack:
		{
			moveToNextPosition(Direction::Directions::down, playfield);
			break;
		}
		case Action::Actions::MoveForward:
		{
			moveToNextPosition(Direction::Directions::up, playfield);
			break;
		}
		case Action::Actions::MoveLeft:
		{
			moveToNextPosition(Direction::Directions::left, playfield);
			break;
		}
		case Action::Actions::MoveRight:
		{
			moveToNextPosition(Direction::Directions::right, playfield);
			break;
		}
		case Action::Actions::Fire:
		{
			fire();
			break;
		}
		default:
		{
			break;
		}
	}
}

void PlayerTank::fire()
{

}

void PlayerTank::moveToNextPosition(const Direction::Directions& direction, BattleField& playfield)
{
	Point nextPosition = computeNextPosition(direction);
	if (nextPosition == m_currentPosition)
	{
		return;
	}

	if (!playfield.isValidPoint(nextPosition) || !playfield.isFreePoint(nextPosition))
	{
		return;
	}
	else
	{
		playfield.setValueInPosition(nextPosition.xPosition, nextPosition.yPosition, m_actorPresent);
		playfield.setValueInPosition(m_currentPosition.xPosition, m_currentPosition.yPosition, emptySpace);
		m_currentPosition = nextPosition;
		m_currentDirection = direction;
	}
	
	 
}

const Point PlayerTank::computeNextPosition(const Direction::Directions& direction)const
{
	Point nextPoint = m_currentPosition;
	switch (direction)
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
