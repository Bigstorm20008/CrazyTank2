#include "MoveLeft.h"


MoveLeft::MoveLeft()
{
}


MoveLeft::~MoveLeft()
{
}

void MoveLeft::execute(ConsoleGame& game) const
{
	if (typeid(*(game.m_pCurrentGameState)).name() == typeid(GameRunning).name())
	{
		game.m_pActor->doAction(Action::MoveLeft, game);
	}
}
