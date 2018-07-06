#pragma once

#include <iostream>

#include "GameState.h"
#include "ConsoleGame.h"
#include "CrazyTank.h"


class GameRunning :
	public GameState
{
public:
	explicit GameRunning(ConsoleGame& game);
	virtual ~GameRunning();

	void update()override;
	void render()override;
private:
	ConsoleGame* m_pGame;
};

