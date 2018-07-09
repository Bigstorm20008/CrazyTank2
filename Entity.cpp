#include "Entity.h"


Entity::Entity(const Point& position, const wchar_t& entityPresent, const unsigned int& durability)
	: m_currentPosition(position), m_presents(entityPresent), m_durability(durability)
{
}


Entity::~Entity()
{
}


const Point& Entity::getPosition()const
{
	return m_currentPosition;
}

const wchar_t& Entity::getPresents()const
{
	return m_presents;
}

void Entity::decreaseHealth()
{
	if (m_durability > 0)
	{
		--m_durability;
	}
}



