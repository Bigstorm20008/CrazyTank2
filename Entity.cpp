#include "Entity.h"


Entity::Entity()
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



