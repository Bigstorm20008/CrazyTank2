#include "WallBlock.h"


WallBlock::WallBlock(const Point& position)
{
	m_currentPosition = position;
	m_presents = wallBlockPresents[0];
	m_durability = wallBlockDurability;
}


WallBlock::~WallBlock()
{
}

void WallBlock::doLogic()
{

}
