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

	for (auto& entity : m_entities)
	{
		delete entity;
		entity = nullptr;
	}

	if (m_pActor)
	{
		delete m_pActor;
		m_pActor = nullptr;
	}
}

void CrazyTank::init()
{
	m_pCurrentGameState = new MenuState;
	m_pInput = new CrazyTankInput;

	m_battleField.init(battleFieldWidth,battleFieldHeight);

	m_entities.reserve(startVectorSizeForEntities);

	initStronghold(strongHoldWidth,strongHoldHeight,strongHoldBlocksPresents);

	Point playerTankStartPoint(actorStartXPosition, actorStartYPosition);
	initPlayerTank(playerTankStartPoint, startTankDirection, playerTankPresents, actorDurability);

	//initWalls(wallBlockPresents, wallsOnBattleField);

	m_backBuffer = m_battleField;
}


void CrazyTank::initWalls(const wchar_t allWallBlockPresents[], const int& wallAmount)
{
	WallCreator wallCreator;

	for (int i = 0; i < wallAmount; ++i)
	{

		Wall wall = wallCreator.createWall(allWallBlockPresents,m_battleField);
		auto& wallBlocks = wall.getWallBlocks();
		for (auto& wallBlock : wallBlocks)
		{
			m_entities.push_back(wallBlock);
			Point position = wallBlock->getPosition();
			int x = position.xPosition;
			int y = position.yPosition;
			m_battleField.setValueInPosition(x, y, allWallBlockPresents[0]);
		}
	}
}

bool CrazyTank::initStronghold(const int& width, const int& height, const wchar_t allStrongHoldBlockPresents[])
{
	StrongHoldCreator creator;
	StrongHold strongHold = creator.createStrongHold(width, height, allStrongHoldBlockPresents, m_battleField);

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
			m_entities.push_back(new WallBlock(position, allStrongHoldBlockPresents));
			m_battleField.setValueInPosition(x, y, allStrongHoldBlockPresents[0]);
		}
		return true;
	}
}


void CrazyTank::initPlayerTank(const Point& tankPosition, const Direction::Directions& tankDirection, const wchar_t& tankPresent, const int& tankDurability)
{
	m_pActor = new PlayerTank(tankPosition, tankDirection, tankPresent, tankDurability);
	m_battleField.setValueInPosition(tankPosition.xPosition, tankPosition.yPosition, tankPresent);
}




