#pragma once

#include "Entity.h"

class WallBlock :
	public Entity
{
public:
	WallBlock(const Point& position, const wchar_t* allPresents);
	virtual ~WallBlock();

	void doLogic()override;
private:
	const wchar_t* m_pAllWallblockPresents;
};

