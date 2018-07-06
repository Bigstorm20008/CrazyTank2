#include "StartGame.h"


StartGame::StartGame()
{
}


StartGame::~StartGame()
{
}

void StartGame::execute(ConsoleGame& game)const 
{
	GameRunning* newState = new GameRunning(game);
	game.setNewState(newState);
}
