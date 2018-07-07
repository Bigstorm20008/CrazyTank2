#include "MoveForward.h"


MoveForward::MoveForward()
{
}


MoveForward::~MoveForward()
{
}

void MoveForward::execute(ConsoleGame& game) const
{
	game.m_pActor->doAction(Action::MoveForward);
}
