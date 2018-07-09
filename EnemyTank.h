#pragma once

#include "DynamicEntity.h"

class EnemyTank :
	public DynamicEntity
{
public:
	explicit EnemyTank(const Point& position, const wchar_t& entityPresent, const unsigned int& durability, const Direction::Directions& direction);
	virtual ~EnemyTank();

	void doLogic(ConsoleGame& game) override;
private:
	

	void procesCollision(const Point& point, ConsoleGame& game)override;
};

