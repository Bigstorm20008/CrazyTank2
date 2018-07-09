#include "StrongHoldCreator.h"


StrongHoldCreator::StrongHoldCreator()
{
}


StrongHoldCreator::~StrongHoldCreator()
{
}

const StrongHold StrongHoldCreator::createStrongHold(const unsigned int& width, const unsigned int& height, const wchar_t* allStrongholdBlockPresents, const BattleField& battlefield)
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

	unsigned int strongholdBlockDurability = wcslen(allStrongholdBlockPresents);
	const wchar_t startBlockPresent = allStrongholdBlockPresents[0];

	Point startPoint(firstWallBlock_XPosition, firstWallBlock_YPosition);
	auto leftWall = constructWall(startPoint, startBlockPresent, strongholdBlockDurability, allStrongholdBlockPresents, height, Direction::up);

	startPoint.yPosition -= (height-1);
	++startPoint.xPosition;
	auto upWall = constructWall(startPoint, startBlockPresent, strongholdBlockDurability, allStrongholdBlockPresents, width, Direction::right);

	startPoint.xPosition += (width-1);
	++startPoint.yPosition;
	auto rightWall = constructWall(startPoint, startBlockPresent, strongholdBlockDurability, allStrongholdBlockPresents, height - 1, Direction::down);

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


const std::vector<WallBlock> StrongHoldCreator::constructWall(const Point& startPoint, const wchar_t& entityPresent, const unsigned int& durability, const wchar_t allWallBlockPresents[],
	                                                          const unsigned int& lenght, const Direction::Directions& direction)
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
				constructedBlocks.push_back(WallBlock(nextPoint, entityPresent, durability, allWallBlockPresents));
				++currentLenght;
			}
			break;
		}
		case Direction::down:
		{
			for (Point nextPoint = startPoint; currentLenght < lenght; ++nextPoint.yPosition)
			{
				constructedBlocks.push_back(WallBlock(nextPoint, entityPresent, durability, allWallBlockPresents));
				++currentLenght;
			}
			break;
		}
		case Direction::left:
		{
			for (Point nextPoint = startPoint; currentLenght < lenght; --nextPoint.xPosition)
			{
				constructedBlocks.push_back(WallBlock(nextPoint, entityPresent, durability, allWallBlockPresents));
				++currentLenght;
			}
			break;
		}
		case Direction::right:
		{
			for (Point nextPoint = startPoint; currentLenght < lenght; ++nextPoint.xPosition)
			{
				constructedBlocks.push_back(WallBlock(nextPoint, entityPresent, durability, allWallBlockPresents));
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
