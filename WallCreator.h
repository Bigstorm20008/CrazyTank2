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
	explicit WallCreator();
	virtual ~WallCreator();
	Wall createWall(const BattleField& battleField);

private:
	std::default_random_engine m_RandomEngine;
	Point generatePoint(const BattleField& battleField);
	bool createWallBlocks(Wall& wall, const Point& startPoint, const BattleField& battleField);
	bool checkPoint(const Point& point, const BattleField& battleField)const;
};

