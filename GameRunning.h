#pragma once

#include <iostream>

#include "GameState.h"
#include "ConsoleGame.h"
#include "CrazyTank.h"


class GameRunning :
	public GameState
{
public:
	friend class StartGame;
	
	virtual ~GameRunning();

	void update()override;
	void render()override;
private:
	ConsoleGame* m_pGame;
	explicit GameRunning(ConsoleGame& game);
};

