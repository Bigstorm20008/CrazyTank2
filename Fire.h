#pragma once

#include "Command.h"

class Fire :
	public Command
{
public:
	friend class CrazyTankInput;
	virtual ~Fire();

	void execute(ConsoleGame& game) const override;

private:
	explicit Fire();
};

