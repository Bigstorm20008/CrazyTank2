#pragma once

#include "Bullet.h"

class PlayerBullet :
	public Bullet
{
public:
	friend class PlayerTank;
	virtual ~PlayerBullet();

	void doLogic(ConsoleGame& game)override;
private:
	explicit PlayerBullet(const Point& position, const wchar_t& entityPresent, const unsigned int& durability, const Direction::Directions& direction);

	void procesCollision(const Point& point, ConsoleGame& game)override;
};

