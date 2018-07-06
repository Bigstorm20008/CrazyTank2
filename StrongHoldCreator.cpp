#include "StrongHoldCreator.h"


StrongHoldCreator::StrongHoldCreator()
{
}


StrongHoldCreator::~StrongHoldCreator()
{
}

const StrongHold StrongHoldCreator::createStrongHold(const int& width, const int& height, const wchar_t allStrongHoldBlockPresents[], const BattleField& battlefield)
{
	StrongHold stronghold(width,height);
	int battleFieldWidth = battlefield.getWidth();
	int battleFieldHeight = battlefield.getHeight();

	if ((height > battleFieldHeight) || (width > battleFieldWidth))
	{
		return stronghold;
	}

	int firstWallBlock_YPosition = battleFieldHeight - 1;
	int firstWallBlock_XPosition = static_cast<int>((battleFieldWidth - width) / 2);

	Point startPoint(firstWallBlock_XPosition, firstWallBlock_YPosition);
	auto leftWall = constructWall(Direction::up, startPoint, height, allStrongHoldBlockPresents);

	startPoint.yPosition -= (height-1);
	++startPoint.xPosition;
	auto upWall = constructWall(Direction::right, startPoint, width, allStrongHoldBlockPresents);

	startPoint.xPosition += (width-1);
	++startPoint.yPosition;
	auto rightWall = constructWall(Direction::down, startPoint, height - 1, allStrongHoldBlockPresents);

	for (auto& block : leftWall)
	{
		stronghold.m_strongHold.push_back(block);
	}

	for (auto& block : upWall)
	{
		stronghold.m_strongHold.push_back(block);
	}

	for (auto& block : rightWall)
	{
		stronghold.m_strongHold.push_back(block);
	}
	
	return stronghold;
}


const std::vector<WallBlock> StrongHoldCreator::constructWall(const Direction::Directions& direction, const Point& startPoint, const int& lenght, const wchar_t allStrongHoldBlockPresents[])
{
	std::vector<WallBlock> constructedBlocks;
	constructedBlocks.reserve(lenght);

	int currentLenght = 0;
	switch (direction)
	{
		case Direction::up:
		{
			for (Point nextPoint = startPoint; currentLenght < lenght; --nextPoint.yPosition)
			{
				constructedBlocks.push_back(WallBlock(nextPoint, allStrongHoldBlockPresents));
				++currentLenght;
			}
			break;
		}
		case Direction::down:
		{
			for (Point nextPoint = startPoint; currentLenght < lenght; ++nextPoint.yPosition)
			{
				constructedBlocks.push_back(WallBlock(nextPoint, allStrongHoldBlockPresents));
				++currentLenght;
			}
			break;
		}
		case Direction::left:
		{
			for (Point nextPoint = startPoint; currentLenght < lenght; --nextPoint.xPosition)
			{
				constructedBlocks.push_back(WallBlock(nextPoint, allStrongHoldBlockPresents));
				++currentLenght;
			}
			break;
		}
		case Direction::right:
		{
			for (Point nextPoint = startPoint; currentLenght < lenght; ++nextPoint.xPosition)
			{
				constructedBlocks.push_back(WallBlock(nextPoint, allStrongHoldBlockPresents));
				++currentLenght;
			}
			break;
		}
		default:
		{
			break;
		}	
	}

	return constructedBlocks;
}
