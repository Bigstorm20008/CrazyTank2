#pragma once


#include "Command.h"
#include "GameRunning.h"


class StartGame :
	public Command
{
public:
	friend class CrazyTankInput;
	virtual ~StartGame();

	void execute(ConsoleGame& game) const override;

private:
	explicit StartGame();
};

