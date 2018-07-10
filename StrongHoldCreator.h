#pragma once

#include "StrongHold.h"
#include "BattleFieldHelpers.h"
#include "Direction.h"

class StrongHoldCreator
{
public:
	friend class CrazyTank;
	
	~StrongHoldCreator();

	const StrongHold createStrongHold(const BattleFieldHelpers& battleFieldHelper);

private:
	explicit StrongHoldCreator(const unsigned int& width, const unsigned int& height, const wchar_t allStrongholdBlockPresents[]);

	unsigned int m_width;
	unsigned int m_height;
	const wchar_t* m_allWallBlockPresents;
	unsigned int m_strongholdBlockDurability;

	const std::vector<WallBlock> constructWall(const Point& startPoint, const unsigned int& lenght, const Direction::Directions& direction);


};

