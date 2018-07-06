#pragma once

#include "Entity.h"

#include "Constants.h"

class WallBlock :
	public Entity
{
public:
	WallBlock(const Point& position);
	virtual ~WallBlock();

	void doLogic()override;
};

