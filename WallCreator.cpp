#include "WallCreator.h"

#include "BattleField.h"

WallCreator::WallCreator(const wchar_t allWallBlockPresents[]) : m_pAllWallBlockPresents(allWallBlockPresents), m_wallBlockDurability(wcslen(allWallBlockPresents))
{
}


WallCreator::~WallCreator()
{
}

Wall WallCreator::createWall(const unsigned int& minWallLenght, const unsigned int maxWallLenght, const BattleFieldHelpers& battleFieldHelper)
{
	RandomEngine* random = nullptr;
	auto engine = random->getInstance();
	const unsigned int wallLenght = engine->getRandomInteger(minWallLenght, maxWallLenght);

	Point freePoint = battleFieldHelper.getRandomFreePoint();

	//Create wallblocks for wall
	Wall wall(wallLenght);
	createWallBlocks(freePoint, wall, battleFieldHelper);

	return wall;
}

bool WallCreator::createWallBlocks(const Point& position, Wall& wall, const BattleFieldHelpers& battleFieldHelper)
{	 

	wall.m_wallBlocks.push_back(new WallBlock(position, m_pAllWallBlockPresents[0], m_wallBlockDurability, m_pAllWallBlockPresents));

	Point nextPoint = position;

	for (int i = 1; i < wall.m_wallLenght; ++i)
	{
		Point rightPoint = position;
		++rightPoint.xPosition;
		if (battleFieldHelper.isFreePoint(rightPoint))
		{
			wall.m_wallBlocks.push_back(new WallBlock(rightPoint, m_pAllWallBlockPresents[0], m_wallBlockDurability, m_pAllWallBlockPresents));
			nextPoint = rightPoint;
			continue;
		}

		Point leftPoint = position;
		--leftPoint.xPosition;
		if (battleFieldHelper.isFreePoint(leftPoint))
		{
			wall.m_wallBlocks.push_back(new WallBlock(leftPoint, m_pAllWallBlockPresents[0], m_wallBlockDurability, m_pAllWallBlockPresents));
			nextPoint = leftPoint;
			continue;
		}

		Point upPoint = position;
		++upPoint.yPosition;
		if (battleFieldHelper.isFreePoint(upPoint))
		{
			wall.m_wallBlocks.push_back(new WallBlock(upPoint, m_pAllWallBlockPresents[0], m_wallBlockDurability, m_pAllWallBlockPresents));
			nextPoint = upPoint;
			continue;
		}

		Point downPoint = position;
		--downPoint.yPosition;
		if (battleFieldHelper.isFreePoint(downPoint))
		{
			wall.m_wallBlocks.push_back(new WallBlock(downPoint, m_pAllWallBlockPresents[0], m_wallBlockDurability, m_pAllWallBlockPresents));
			nextPoint = downPoint;
			continue;
		}

		for (auto& wallBlock : wall.m_wallBlocks)
		{
			delete wallBlock;
			wallBlock = nullptr;
			return false;
		}
		
	}

	return true;
}


