#include "WallBlock.h"


WallBlock::WallBlock(const Point& position, const wchar_t* allPresents)
{
	m_currentPosition = position;	
	
	m_pAllWallblockPresents = allPresents;
	m_durability = wcslen(m_pAllWallblockPresents);
	m_presents = m_pAllWallblockPresents[0];
}


WallBlock::~WallBlock()
{
}

void WallBlock::doLogic(ConsoleGame& game)
{
	int arraySize = wcslen(m_pAllWallblockPresents);
	int presentsIndex = arraySize - m_durability;

	if (presentsIndex == arraySize)
	{
		game.m_entitiesToDelete.push_back(this);
	}

	if (m_presents != m_pAllWallblockPresents[presentsIndex])
	{
		m_presents = m_pAllWallblockPresents[presentsIndex];
		game.m_backBuffer.setValueInPosition(m_currentPosition.xPosition,m_currentPosition.yPosition, m_presents);
	}
}

