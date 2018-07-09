#include "WallBlock.h"


WallBlock::WallBlock(const Point& position, const wchar_t& entityPresent, const unsigned int& durability, const wchar_t* allPresents)
	: Entity(position, entityPresent, durability), m_pAllWallblockPresents(allPresents)
{
}


WallBlock::~WallBlock()
{
}

void WallBlock::doLogic(ConsoleGame& game)
{
	size_t arraySize = wcslen(m_pAllWallblockPresents);
	size_t presentsIndex = arraySize - m_durability;

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

