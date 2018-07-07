#pragma once

#include "Actor.h"

class PlayerTank :
	public Actor
{
public:
	explicit PlayerTank(const Point& tankPosition, const Direction::Directions& tankDirection, const wchar_t& tankPresent, const int& tankDurability);
	virtual ~PlayerTank();

	void doAction(const Action::Actions& action, BattleField& playfield)override;
private:
	void moveToNextPosition(const Direction::Directions& direction, BattleField& playfield);
	void fire();

	const Point computeNextPosition(const Direction::Directions& direction)const;
};

