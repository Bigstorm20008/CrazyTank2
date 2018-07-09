#pragma once
#include "Command.h"

class MoveForward :
	public Command
{
public:
	friend class CrazyTankInput;
	
	virtual ~MoveForward();
	void execute(ConsoleGame& game) const override;

private:
	explicit MoveForward();
};

