#include "EnemyTankCreator.h"


EnemyTankCreator::EnemyTankCreator(const wchar_t& enemyTankPresent, const unsigned int& enemyTankDurability, const unsigned int offsetBetweenTanks)
	: m_tankPresent(enemyTankPresent), m_Durability(enemyTankDurability), m_offsetBetweenTanks(offsetBetweenTanks) 
{
	
}


EnemyTankCreator::~EnemyTankCreator()
{
}

EnemyTank* EnemyTankCreator::createEnemyTank(const BattleField& battleField)
{
	BattleFieldHelpers helpers(battleField);
	Point randomFreePoint;
	do
	{
		randomFreePoint = helpers.getRandomFreePoint();
	} 
	while (!checkAreaArroundPoint(randomFreePoint, helpers));

	EnemyTank* tank = new EnemyTank(randomFreePoint, 'S', 3, Direction::down);
	
	return tank;
}

bool EnemyTankCreator::checkAreaArroundPoint(const Point& point, const BattleFieldHelpers& battleFieldHelpers)const
{
	Point pointToCheck = point;
	pointToCheck.xPosition -= m_offsetBetweenTanks;
	pointToCheck.yPosition -= m_offsetBetweenTanks;

	for (pointToCheck.yPosition; pointToCheck.yPosition <= point.yPosition + m_offsetBetweenTanks; ++pointToCheck.yPosition)
	{
		for (pointToCheck.xPosition; pointToCheck.xPosition <= point.xPosition + m_offsetBetweenTanks; ++pointToCheck.xPosition)
		{
			if (battleFieldHelpers.isValidPoint(pointToCheck))
			{
				if (battleFieldHelpers.getValueInPosition(pointToCheck) == m_tankPresent)
				{
					return false;
				}
			}
		}
		pointToCheck.xPosition = point.xPosition - 2 * m_offsetBetweenTanks;
	}
	return true;
}