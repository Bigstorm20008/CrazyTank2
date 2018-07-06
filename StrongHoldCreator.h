#pragma once

#include "StrongHold.h"
#include "BattleField.h"
#include "Direction.h"

class StrongHoldCreator
{
public:
	explicit StrongHoldCreator();
	virtual ~StrongHoldCreator();

	const StrongHold createStrongHold(const int& width,const int& height, const BattleField& battlefield);

private:
	const std::vector<WallBlock> constructWall(const Direction::Directions& direction, const Point& startPoint, const int& lenght);


};

