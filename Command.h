#pragma once

class ConsoleGame;
#include "ConsoleGame.h"

class Command
{
public:
	explicit Command();
	virtual ~Command();

	virtual void execute(ConsoleGame& game) const  = 0;
};

