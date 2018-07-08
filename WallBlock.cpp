#include "WallBlock.h"


WallBlock::WallBlock(const Point& position, const wchar_t* allPresents)
{
	m_currentPosition = position;	
	m_durability = sizeof(allPresents) / sizeof(wchar_t);
	m_pAllWallblockPresents = allPresents;
	m_presents = m_pAllWallblockPresents[0];
}


WallBlock::~WallBlock()
{
}

void WallBlock::doLogic(BattleField& backBufferField)
{

}

