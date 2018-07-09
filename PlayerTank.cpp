#include "PlayerTank.h"


PlayerTank::PlayerTank(const Point& tankPosition, const Direction::Directions& tankDirection, const wchar_t& tankPresent, const int& tankDurability) 
	: Actor(tankPosition,tankDirection,tankPresent,tankDurability)
{
}


PlayerTank::~PlayerTank()
{
}

void PlayerTank::doAction(const Action::Actions& action, ConsoleGame& game)
{
	switch (action)
	{
		case Action::Actions::MoveBack:
		{
			moveToNextPosition(Direction::Directions::down, game.m_backBuffer);
			break;
		}
		case Action::Actions::MoveForward:
		{
			moveToNextPosition(Direction::Directions::up, game.m_backBuffer);
			break;
		}
		case Action::Actions::MoveLeft:
		{
			moveToNextPosition(Direction::Directions::left, game.m_backBuffer);
			break;
		}
		case Action::Actions::MoveRight:
		{
			moveToNextPosition(Direction::Directions::right, game.m_backBuffer);
			break;
		}
		case Action::Actions::Fire:
		{
			fire(game);
			break;
		}
		default:
		{
			break;
		}
	}
}

void PlayerTank::fire(ConsoleGame& game)
{
	Point nextPoint = computeNextPosition(m_currentDirection);
	if (nextPoint == m_currentPosition)
	{
		return;
	}

	if (!game.m_backBuffer.isValidPoint(nextPoint))
	{
		return;
	}

	if (!game.m_backBuffer.isFreePoint(nextPoint))
	{
		//process collision;
		Entity* entity = game.getEntityAtPoint(nextPoint);
		if (entity)
		{
			entity->decreaseHealth();
		}
		return;
	}
	else
	{
		PlayerBullet* bullet = new PlayerBullet(nextPoint, bulletPresent, bulletDurability, m_currentDirection);
		game.m_entities.push_back(bullet);
		game.m_backBuffer.setValueInPosition(nextPoint.xPosition, nextPoint.yPosition, bulletPresent);
	}

}

void PlayerTank::moveToNextPosition(const Direction::Directions& direction, BattleField& playfield)
{
	Point nextPosition = computeNextPosition(direction);
	m_currentDirection = direction;
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
