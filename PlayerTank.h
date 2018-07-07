#pragma once

#include "Actor.h"

class PlayerTank :
	public Actor
{
public:
	explicit PlayerTank(const Point& tankPosition, const Direction::Directions& tankDirection, const wchar_t& tankPresent, const int& tankDurability);
	virtual ~PlayerTank();

	void doAction(const Action::Actions& action)override;
};

