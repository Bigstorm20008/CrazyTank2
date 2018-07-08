#pragma once

#include "Entity.h"

class WallBlock :
	public Entity
{
public:
	explicit WallBlock(const Point& position, const wchar_t* allPresents);
	virtual ~WallBlock();

	void doLogic(ConsoleGame& game)override;

private:
	const wchar_t* m_pAllWallblockPresents;	
};

