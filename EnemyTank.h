#pragma once

#include "DynamicEntity.h"

class EnemyTank :
	public DynamicEntity
{
public:
	friend class EnemyTankCreator;
	
	virtual ~EnemyTank();

	void doLogic(ConsoleGame& game) override;

private:
	explicit EnemyTank(const Point& position, const wchar_t& entityPresent, const unsigned int& durability, const Direction::Directions& direction);
	void procesCollision(const Point& point, ConsoleGame& game)override;
};

