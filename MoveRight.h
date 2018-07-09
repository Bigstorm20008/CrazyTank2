#pragma once
#include "Command.h"
class MoveRight :
	public Command
{
public:
	friend class CrazyTankInput;
	
	virtual ~MoveRight();

	void execute(ConsoleGame& game) const override;

private:
	explicit MoveRight();
};

