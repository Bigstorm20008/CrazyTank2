#include "Fire.h"


Fire::Fire()
{
}


Fire::~Fire()
{
}

void Fire::execute(ConsoleGame& game) const
{
	if (typeid(*(game.m_pCurrentGameState)).name() == typeid(GameRunning).name())
	{
		game.m_pActor->doAction(Action::Fire, game);
	}
}
