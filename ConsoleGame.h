#pragma once

#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <typeinfo>

//forward declaration
class Input;
#include "Input.h"

#include "GameState.h"

class ConsoleGame
{
public:
	explicit ConsoleGame();
	virtual ~ConsoleGame();

	//intialize input for game and start game state in this function
	virtual void init() = 0;

	int run();

	void setNewState(GameState* const pState);
	
	
	

protected:
	Input* m_pInput;
	GameState* m_pCurrentGameState;

private:
	bool m_isRunning;
	
};

