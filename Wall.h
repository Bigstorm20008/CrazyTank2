#pragma once

#include <vector>

#include "WallCreator.h"
#include "WallBlock.h"

class Wall
{
public:
	friend class WallCreator;

	
	~Wall();

	const std::vector<WallBlock*>& getWallBlocks() const;
private:
	explicit Wall(int wallLenght);

	int m_wallLenght;
	std::vector<WallBlock*> m_wallBlocks;
};

