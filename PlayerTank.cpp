#include "PlayerTank.h"


PlayerTank::PlayerTank(const Point& tankPosition, const Direction::Directions& tankDirection, const wchar_t& tankPresent, const int& tankDurability) 
	: Actor(tankPosition,tankDirection,tankPresent,tankDurability)
{
}


PlayerTank::~PlayerTank()
{
}

void PlayerTank::doAction(const Action::Actions& action)
{

}
