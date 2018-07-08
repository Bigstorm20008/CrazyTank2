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
#include "Actor.h"

class Entity;
#include "Entity.h"
#include "Constants.h"


class ConsoleGame
{
public:
	//friend State classes
	friend class GameRunning;

	//friend Command classes
	friend class StartGame;
	friend class MoveForward;
	friend class MoveBack;
	friend class MoveRight;
	friend class MoveLeft;
	friend class Fire;

	friend class Actor;
	friend class PlayerTank;

	friend class WallBlock;
	friend class PlayerBullet;
	friend class DynamicEntity;

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
	BattleField m_backBuffer;

	std::vector<Entity*> m_entities;
	Actor* m_pActor;

	void printBattleField()const;
	void setNewState(GameState* pState);
	
private:
	std::vector<Entity*> m_entitiesToDelete;
	bool m_isRunning;
	Entity* getEntityAtPoint(const Point& point) const;
	

	
	
};

