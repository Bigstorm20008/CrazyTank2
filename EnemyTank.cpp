#include "EnemyTank.h"


EnemyTank::EnemyTank(const Point& position, const wchar_t& entityPresent, const unsigned int& durability, const Direction::Directions& direction)
	: DynamicEntity(position,entityPresent,durability,direction)
{
}


EnemyTank::~EnemyTank()
{

}

void EnemyTank::doLogic(ConsoleGame& game)
{
	if (m_durability == 0)
	{
		reinterpret_cast<CrazyTank*>(&game)->m_entitiesToDelete.push_back(this);
		return;
	}
}

void EnemyTank::procesCollision(const Point& point, ConsoleGame& game)
{

}
