#pragma once

#include<random>
#include<ctime>


#include "BattleFieldHelpers.h"
#include "RandomEngine.h"


class Wall;
#include "Wall.h"

class WallCreator
{
public:
	friend class CrazyTank;

	
	~WallCreator();
	Wall createWall(const unsigned int& minWallLenght,const unsigned int maxWallLenght, const BattleFieldHelpers& battleFieldHelper);

private:
	explicit WallCreator(const wchar_t allWallBlockPresents[]);

	bool createWallBlocks(const Point& position, Wall& wall, const BattleFieldHelpers& battleFieldHelper);

	const wchar_t* m_pAllWallBlockPresents;
	const unsigned int m_wallBlockDurability;
};

