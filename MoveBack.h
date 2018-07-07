#pragma once
#include "Command.h"

class MoveBack :
	public Command
{
public:
	explicit MoveBack();
	virtual ~MoveBack();

	void execute(ConsoleGame& game) const override;
};

