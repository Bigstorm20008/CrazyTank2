#pragma once
#include "Command.h"
class MoveRight :
	public Command
{
public:
	explicit MoveRight();
	virtual ~MoveRight();

	void execute(ConsoleGame& game) const override;
};

