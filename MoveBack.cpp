#include "MoveBack.h"


MoveBack::MoveBack()
{
}


MoveBack::~MoveBack()
{
}

void MoveBack::execute(ConsoleGame& game) const
{
	if (typeid(*(game.m_pCurrentGameState)).name() == typeid(GameRunning).name())
	{
		game.m_pActor->doAction(Action::MoveBack, game);
	}
}
