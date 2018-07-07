#include "Actor.h"


Actor::Actor(const Point& actorPosition, const Direction::Directions& actorDirection, const wchar_t& actorPresent, const int& actorDurability)
{
	m_actorPresent = actorPresent;
	m_currentDirection = actorDirection;
	m_currentDurability = actorDurability;
	m_currentPosition = actorPosition;
}


Actor::~Actor()
{
}
