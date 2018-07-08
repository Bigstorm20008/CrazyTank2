#pragma once

#include "Entity.h"

class DynamicEntity :
	public Entity
{
public:
	explicit DynamicEntity();
	virtual ~DynamicEntity();

	
private:
	void goToNextPositon(BattleField& battlefield);
	const Point computeNextPosition()const;
	virtual void procesCollision(const wchar_t& collision) = 0;
};

