#include "BattleFieldHelpers.h"


BattleFieldHelpers::BattleFieldHelpers(const BattleField& battlefield) : m_battleField(&battlefield)
{
}


BattleFieldHelpers::~BattleFieldHelpers()
{
}

Point BattleFieldHelpers::getRandomFreePoint()const
{
	Point foundedPoint;
	do
	{
		foundedPoint = generatePoint();
	} while (!isFreePoint(foundedPoint));

	return foundedPoint;	
}

bool BattleFieldHelpers::isFreePoint(const Point& point)const
{
	if (m_battleField->isValidPoint(point) && (m_battleField->isFreePoint(point)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Point BattleFieldHelpers::generatePoint()const
{
	int battleFieldWidth = m_battleField->getWidth();
	int battleFieldHeight = m_battleField->getHeight();

	RandomEngine* randomEngine = nullptr;
	auto instance = randomEngine->getInstance();
	
	int x = instance->getRandomInteger(0, (battleFieldWidth - 1));
	int y = instance->getRandomInteger(0, (battleFieldHeight - 1));
	return Point(x, y);
}

const wchar_t& BattleFieldHelpers::getValueInPosition(const Point& point)const
{  
   return m_battleField->getValueInPosition(point.xPosition,point.yPosition);
}

bool BattleFieldHelpers::isValidPoint(const Point& point)const
{
	return m_battleField->isValidPoint(point);
}

const unsigned int& BattleFieldHelpers::getWidth()const
{
	return m_battleField->getWidth();
}

const unsigned int& BattleFieldHelpers::getHeight()const
{
	return m_battleField->getHeight();
}
