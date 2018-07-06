#include "Wall.h"


Wall::Wall(int wallLenght)
{
	m_wallLenght = wallLenght;
	m_wallBlocks.reserve(wallLenght);
}


Wall::~Wall()
{
}

const std::vector<WallBlock*>& Wall::getWallBlocks() const
{
	return m_wallBlocks;
}
