#pragma once

#include "Entity.h"

class DynamicEntity :
	public Entity
{
public:
	explicit DynamicEntity();
	virtual ~DynamicEntity();

	const Direction::Directions& getDirection()const;

protected:
	Direction::Directions m_direction;
	void goToNextPositon(ConsoleGame& game);
private:
	const Point computeNextPosition()const;
	virtual void procesCollision(const Point& point, ConsoleGame& game) = 0;
};

