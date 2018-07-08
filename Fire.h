#pragma once

#include "Command.h"

class Fire :
	public Command
{
public:
	explicit Fire();
	virtual ~Fire();

	void execute(ConsoleGame& game) const override;
};

