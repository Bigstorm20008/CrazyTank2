#include "MoveRight.h"


MoveRight::MoveRight()
{
}


MoveRight::~MoveRight()
{
}

void MoveRight::execute(ConsoleGame& game) const
{
	if (typeid(*(game.m_pCurrentGameState)).name() == typeid(GameRunning).name())
	{
		game.m_pActor->doAction(Action::MoveRight, game.m_backBuffer);
	}
}
