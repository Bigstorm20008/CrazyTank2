#pragma once


#include "Command.h"
#include "GameRunning.h"


class StartGame :
	public Command
{
public:
	explicit StartGame();
	virtual ~StartGame();

	void execute(ConsoleGame& game) const override;
};

