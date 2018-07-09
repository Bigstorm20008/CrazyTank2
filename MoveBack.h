#pragma once
#include "Command.h"

class MoveBack :
	public Command
{
public:
	friend class CrazyTankInput;
	
	virtual ~MoveBack();

	void execute(ConsoleGame& game) const override;

private:
	explicit MoveBack();
};

