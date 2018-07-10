#include "StrongHoldCreator.h"


StrongHoldCreator::StrongHoldCreator(const unsigned int& width, const unsigned int& height, const wchar_t allStrongholdBlockPresents[])
	: m_width(width), m_height(height), m_allWallBlockPresents(allStrongholdBlockPresents), m_strongholdBlockDurability(wcslen(allStrongholdBlockPresents))
{
}


StrongHoldCreator::~StrongHoldCreator()
{
}

const StrongHold StrongHoldCreator::createStrongHold(const BattleFieldHelpers& battleFieldHelper)
{
	StrongHold stronghold(m_width,m_height);
	unsigned int battleFieldWidth = battleFieldHelper.getWidth();
	unsigned int battleFieldHeight = battleFieldHelper.getHeight();

	if ((m_height > battleFieldHeight) || (m_width > battleFieldWidth))
	{
		return stronghold;
	}

	int firstWallBlock_YPosition = battleFieldHeight - 1;
	int firstWallBlock_XPosition = static_cast<int>((battleFieldWidth - m_width) / 2);

	const wchar_t startBlockPresent = m_allWallBlockPresents[0];

	Point startPoint(firstWallBlock_XPosition, firstWallBlock_YPosition);
	auto leftWall = constructWall(startPoint, m_height, Direction::up);

	startPoint.yPosition -= (m_height-1);
	++startPoint.xPosition;
	auto upWall = constructWall(startPoint, m_width, Direction::right);

	startPoint.xPosition += (m_width-1);
	++startPoint.yPosition;
	auto rightWall = constructWall(startPoint, m_height - 1, Direction::down);

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


const std::vector<WallBlock> StrongHoldCreator::constructWall(const Point& startPoint, const unsigned int& lenght, const Direction::Directions& direction)
{
	std::vector<WallBlock> constructedBlocks;
	constructedBlocks.reserve(lenght);

	unsigned int currentLenght = 0;
	switch (direction)
	{
		case Direction::up:
		{
			for (Point nextPoint = startPoint; currentLenght < lenght; --nextPoint.yPosition)
			{
				constructedBlocks.push_back(WallBlock(nextPoint, m_allWallBlockPresents[0], m_strongholdBlockDurability, m_allWallBlockPresents));
				++currentLenght;
			}
			break;
		}
		case Direction::down:
		{
			for (Point nextPoint = startPoint; currentLenght < lenght; ++nextPoint.yPosition)
			{
				constructedBlocks.push_back(WallBlock(nextPoint, m_allWallBlockPresents[0], m_strongholdBlockDurability, m_allWallBlockPresents));
				++currentLenght;
			}
			break;
		}
		case Direction::left:
		{
			for (Point nextPoint = startPoint; currentLenght < lenght; --nextPoint.xPosition)
			{
				constructedBlocks.push_back(WallBlock(nextPoint, m_allWallBlockPresents[0], m_strongholdBlockDurability, m_allWallBlockPresents));
				++currentLenght;
			}
			break;
		}
		case Direction::right:
		{
			for (Point nextPoint = startPoint; currentLenght < lenght; ++nextPoint.xPosition)
			{
				constructedBlocks.push_back(WallBlock(nextPoint, m_allWallBlockPresents[0], m_strongholdBlockDurability, m_allWallBlockPresents));
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
