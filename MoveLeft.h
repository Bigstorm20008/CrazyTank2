#pragma once
#include "Command.h"
class MoveLeft :
	public Command
{
public:
	explicit MoveLeft();
	virtual ~MoveLeft();

	void execute(ConsoleGame& game) const override;
};

