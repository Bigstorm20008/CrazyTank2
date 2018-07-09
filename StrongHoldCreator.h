#pragma once

#include "StrongHold.h"
#include "BattleField.h"
#include "Direction.h"

class StrongHoldCreator
{
public:
	friend class CrazyTank;
	
	~StrongHoldCreator();

	const StrongHold createStrongHold(const unsigned int& width, const unsigned int& height, const wchar_t allStrongholdBlockPresents[], const BattleField& battlefield);

private:
	explicit StrongHoldCreator();

	const std::vector<WallBlock> constructWall(const Point& startPoint, const wchar_t& entityPresent, const unsigned int& durability, const wchar_t* allWallBlockPresents,
		                                       const unsigned int& lenght, const Direction::Directions& direction);


};

