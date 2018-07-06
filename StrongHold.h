#pragma once

#include <vector>

#include "WallBlock.h"

class StrongHold
{
public:
	friend class StrongHoldCreator;

	explicit StrongHold();
	virtual ~StrongHold();

	const std::vector<WallBlock>& getStrohgHoldBlocks()const;
private:
	std::vector<WallBlock> m_strongHold;
};

