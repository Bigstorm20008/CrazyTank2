#pragma once

#include "Entity.h"

class BattleTank :
	public Entity
{
public:
	BattleTank();
	virtual ~BattleTank();

	void goToNextPosition();
};

