#pragma once
#include "Command.h"
class MoveLeft :
	public Command
{
public:
	friend class CrazyTankInput;

	virtual ~MoveLeft();

	void execute(ConsoleGame& game) const override;

private:
	explicit MoveLeft();
};

