#pragma once

#include <vector>

#include "WallBlock.h"

class StrongHold
{
public:
	friend class StrongHoldCreator;

	
	~StrongHold();

	const std::vector<WallBlock>& getStrohgHoldBlocks()const;
private:
	explicit StrongHold(const int& width, const int height);

	std::vector<WallBlock> m_strongHold;
	int m_width;
	int m_height;
};

