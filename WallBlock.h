#pragma once

#include "Entity.h"

class WallBlock :
	public Entity
{
public:
	friend class StrongHoldCreator;
	friend class WallCreator;
	
	~WallBlock();

	void doLogic(ConsoleGame& game)override;

private:
	explicit WallBlock(const Point& position, const wchar_t& entityPresent, const unsigned int& durability, const wchar_t* allPresents);

	const wchar_t* m_pAllWallblockPresents;	
};

