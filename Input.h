#pragma once

class Command;
#include "Command.h"

class Input
{
public:
	Input();
	virtual ~Input();

	virtual const Command* const messageHandler(const wchar_t& userInput) = 0;
};

