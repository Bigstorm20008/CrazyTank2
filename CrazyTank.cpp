#include "CrazyTank.h"


CrazyTank::CrazyTank() : ConsoleGame()
{
}


CrazyTank::~CrazyTank()
{
	if (m_pCurrentGameState)
	{
		delete m_pCurrentGameState;
		m_pCurrentGameState = nullptr;
	}

	if (m_pInput)
	{
		delete m_pInput;
		m_pInput = nullptr;
	}
}

void CrazyTank::init()
{
	m_pCurrentGameState = new MenuState;
	m_pInput = new CrazyTankInput;

	m_battleField.init(battleFieldWidth,battleFieldHeight);

	m_entities.reserve(startVectorSizeForEntities);

	initStronghold();
	initWalls(wallsOnBattleField);
}


void CrazyTank::initWalls(const int& wallAmount)
{
	WallCreator wallCreator;

	for (int i = 0; i < wallAmount; ++i)
	{

		Wall wall = wallCreator.createWall(m_battleField);
		auto& wallBlocks = wall.getWallBlocks();
		for (auto& wallBlock : wallBlocks)
		{
			m_entities.push_back(wallBlock);
			Point position = wallBlock->getPosition();
			int x = position.xPosition;
			int y = position.yPosition;
			m_battleField.setValueInPosition(x, y, wallBlockPresents[0]);
		}
	}

}

bool CrazyTank::initStronghold()
{
	StrongHoldCreator creator;
	StrongHold strongHold = creator.createStrongHold(m_battleField);

	auto strongHoldBlocks = strongHold.getStrohgHoldBlocks();
	if (strongHoldBlocks.empty())
	{
		return false;
	}
	else
	{
		for (auto& block : strongHoldBlocks)
		{
			Point position = block.getPosition();
			int x = position.xPosition;
			int y = position.yPosition;
			m_entities.push_back(new WallBlock(position));
			m_battleField.setValueInPosition(x, y, wallBlockPresents[0]);
		}
		return true;
	}
}




