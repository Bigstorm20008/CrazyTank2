#pragma once

#include "DynamicEntity.h"

class PlayerBullet :
	public DynamicEntity
{
public:
	friend class PlayerTank;
	virtual ~PlayerBullet();

	void doLogic(ConsoleGame& game)override;
private:
	explicit PlayerBullet(const Point& startPostion, const Direction::Directions& direction, const wchar_t& bulletPresent);

	void procesCollision(const Point& point, ConsoleGame& game)override;
};

