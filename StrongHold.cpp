#include "StrongHold.h"


StrongHold::StrongHold(const int& width, const int height)
{
	m_width = width;
	m_height = height;
}


StrongHold::~StrongHold()
{
}

const std::vector<WallBlock>& StrongHold::getStrohgHoldBlocks()const
{
	return m_strongHold;
}
