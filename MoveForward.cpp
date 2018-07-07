#include "MoveForward.h"


MoveForward::MoveForward()
{
}


MoveForward::~MoveForward()
{
}

void MoveForward::execute(ConsoleGame& game) const
{
	if (typeid(*(game.m_pCurrentGameState)).name() == typeid(GameRunning).name())
	{
		game.m_pActor->doAction(Action::MoveForward, game.m_backBuffer);
	}
}
