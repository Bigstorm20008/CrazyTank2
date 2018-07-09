#pragma once

#include<random>
#include<ctime>



class BattleField;
#include "BattleField.h"

class Wall;
#include "Wall.h"

class WallCreator
{
public:
	friend class CrazyTank;

	
	~WallCreator();
	Wall createWall(const wchar_t allWallBlockPresents[], const BattleField& battleField);

private:
	explicit WallCreator();

	std::default_random_engine m_RandomEngine;
	Point generatePoint(const BattleField& battleField);
	bool createWallBlocks(const Point& position, const wchar_t* allWallBlockPresents, Wall& wall, const BattleField& battleField);
	bool checkPoint(const Point& point, const BattleField& battleField)const;
};

