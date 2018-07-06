#include "WallCreator.h"

#include "BattleField.h"

WallCreator::WallCreator()
{
	m_RandomEngine = std::default_random_engine(static_cast<unsigned int>(time(0)));
}


WallCreator::~WallCreator()
{
}

Wall WallCreator::createWall(const wchar_t allWallBlockPresents[], const BattleField& battleField)
{
	std::uniform_int_distribution<int> distance(1, 6);
	
	//Generate random wall lenght
	int wallLenght = distance(m_RandomEngine);

	//Generate random start point for wall
	Point startPoint;
	do
	{ 
		startPoint = generatePoint(battleField);
	}while (!battleField.isFreePoint(startPoint));

	//Create wallblocks for wall
	Wall wall(wallLenght);
	createWallBlocks(wall, allWallBlockPresents, startPoint, battleField);

	return wall;
}

Point WallCreator::generatePoint(const BattleField& battleField)
{
	int battleFieldWidth = battleField.getWidth();
	int battleFieldHeight = battleField.getHeight();

	std::uniform_int_distribution<int> widthDistance(0, battleFieldWidth - 1);
	std::uniform_int_distribution<int> heightDistance(0, battleFieldHeight - 1);

	int x = widthDistance(m_RandomEngine);
	int y = heightDistance(m_RandomEngine);

	return Point(x, y);
}

bool WallCreator::createWallBlocks(Wall& wall, const wchar_t allWallBlockPresents[], const Point& startPoint, const BattleField& battleField)
{

	wall.m_wallBlocks.push_back(new WallBlock(startPoint, allWallBlockPresents));

	Point nextPoint = startPoint;

	for (int i = 1; i < wall.m_wallLenght; ++i)
	{
		Point rightPoint = startPoint;
		++rightPoint.xPosition;
		if (checkPoint(rightPoint, battleField))
		{
			wall.m_wallBlocks.push_back(new WallBlock(rightPoint, allWallBlockPresents));
			nextPoint = rightPoint;
			continue;
		}

		Point leftPoint = startPoint;
		--leftPoint.xPosition;
		if (checkPoint(leftPoint, battleField))
		{
			wall.m_wallBlocks.push_back(new WallBlock(leftPoint, allWallBlockPresents));
			nextPoint = leftPoint;
			continue;
		}

		Point upPoint = startPoint;
		++upPoint.yPosition;
		if (checkPoint(upPoint, battleField))
		{
			wall.m_wallBlocks.push_back(new WallBlock(upPoint, allWallBlockPresents));
			nextPoint = upPoint;
			continue;
		}

		Point downPoint = startPoint;
		--downPoint.yPosition;
		if (checkPoint(downPoint, battleField))
		{
			wall.m_wallBlocks.push_back(new WallBlock(downPoint, allWallBlockPresents));
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

bool WallCreator::checkPoint(const Point& point, const BattleField& battleField)const
{
	if (battleField.isValidPoint(point) && (battleField.isFreePoint(point)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
