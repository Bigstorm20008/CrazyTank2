#pragma once

#include <vector>

#include "WallCreator.h"
#include "WallBlock.h"

class Wall
{
public:
	friend class WallCreator;

	explicit Wall(int wallLenght);
	virtual ~Wall();

	const std::vector<WallBlock*>& getWallBlocks() const;
private:
	int m_wallLenght;
	std::vector<WallBlock*> m_wallBlocks;
};

