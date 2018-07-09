#pragma once

#include "DynamicEntity.h"

class Bullet :
	public DynamicEntity
{
public:
	Bullet(const Point& position, const wchar_t& entityPresent, const unsigned int& durability, const Direction::Directions& direction);
	virtual ~Bullet();

	void goToNextPositon(ConsoleGame& game);
};

