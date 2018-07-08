#pragma once

#include <iostream>


#include "GameState.h"

class GamePaused :
	public GameState
{
public:
	explicit GamePaused();
	virtual ~GamePaused();

	void update()override;
	void render()override;
};

