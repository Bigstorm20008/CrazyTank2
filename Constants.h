#pragma once

#include "Direction.h"

//CrazyTanks constants
const unsigned int wallsOnBattleField = 100U;
const unsigned int minWallLenght = 1U;
const unsigned int maxWallLenght = 6U;
const unsigned int startVectorSizeForEntities = 500U;

//PlayField constans
const unsigned int battleFieldWidth = 40U;
const unsigned int battleFieldHeight = 20U;
const wchar_t emptySpace = ' ';

//StrongHold constans
const unsigned int strongHoldWidth = 10U;
const unsigned int strongHoldHeight = 4U;


//WallBlock constants
const wchar_t wallBlockPresents[] = { 'X','U','I' };


//StrongHold constants
const wchar_t strongHoldBlocksPresents[] = { 'H', 'K', 'Y' };

//PlayerTank constans
const wchar_t playerTankPresents = 'T';
const Direction::Directions startTankDirection = Direction::Directions::up;
const unsigned int actorStartXPosition = ((battleFieldWidth - strongHoldWidth) / 2) + strongHoldWidth + 2;
const unsigned int actorStartYPosition = battleFieldHeight - 1;
const unsigned int actorDurability = 3U;

//Bullet
const wchar_t bulletPresent = ':';
const unsigned int bulletDurability = 1;

//Enemy tanks
const unsigned int enemyAmount = 10U;
const wchar_t enemyTankPresent = 'S';
const unsigned int enemyTankDurability = 3U;
const unsigned int offsetBeetwenTanks = 3U;



