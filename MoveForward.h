#pragma once
#include "Command.h"

class MoveForward :
	public Command
{
public:
	MoveForward();
	virtual ~MoveForward();
	void execute(ConsoleGame& game) const override;
};

