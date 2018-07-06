#include "BattleTank.h"


BattleTank::BattleTank()
{
}


BattleTank::~BattleTank()
{
}

void BattleTank::goToNextPosition()
{
	Point nextPoint;
	switch (m_direction.direction)
	{
		case Direction::down:
		{
			++nextPoint.yPosition;
			break;
		}
		case Direction::up:
		{
			--nextPoint.yPosition;
			break;
		}
		case Direction::left:
		{
			--nextPoint.xPosition;
			break;
		}
		case Direction::right:
		{
			++nextPoint.xPosition;
			break;
		}
		default:
		{
			break;
		}
	}
}