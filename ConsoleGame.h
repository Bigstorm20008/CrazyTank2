#pragma once

#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <typeinfo>

//forward declaration
class Input;
#include "Input.h"

#include "GameState.h"
#include "BattleField.h"

#include "Constants.h"


class ConsoleGame
{
public:
	friend class GameRunning;
	friend class StartGame;

	explicit ConsoleGame();
	virtual ~ConsoleGame();

	//intialize input for game and start game state in this function
	//Call BattleField::init() in this function
	virtual void init() = 0;

	int run();

protected:
	Input* m_pInput;
	GameState* m_pCurrentGameState;
	BattleField m_battleField;

	std::vector<Entity*> m_entities;

	void printBattleField()const;
	void setNewState(GameState* pState);
	bool checkCollisions(const Entity* const entity);
private:
	bool m_isRunning;

	
	
};

