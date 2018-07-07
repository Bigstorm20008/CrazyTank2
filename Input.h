#pragma once

class Command;
#include "Command.h"

class Input
{
public:
	Input();
	virtual ~Input();

	virtual const Command* const messageHandler(wchar_t& userInput) = 0;
};

