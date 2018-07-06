#pragma once

#include "StrongHold.h"
#include "BattleField.h"
#include "Direction.h"

#include "Constants.h"

class StrongHoldCreator
{
public:
	explicit StrongHoldCreator();
	virtual ~StrongHoldCreator();

	const StrongHold createStrongHold(const BattleField& battlefield);

private:
	const std::vector<WallBlock> constructWall(const Direction::Directions direction, const Point& startPoint, const int& lenght);


};

