#pragma once

#include "Direction.h"

//CrazyTanks constants
const unsigned int wallsOnBattleField = 100;
const unsigned int startVectorSizeForEntities = 500;

//PlayField constans
const unsigned int battleFieldWidth = 40;
const unsigned int battleFieldHeight = 20;
const wchar_t emptySpace = ' ';

//StrongHold constans
const unsigned int strongHoldWidth = 10;
const unsigned int strongHoldHeight = 4;


//WallBlock constants
const wchar_t wallBlockPresents[] = { 'X','U','I' };


//StrongHold constants
const wchar_t strongHoldBlocksPresents[] = { 'H', 'K', 'Y' };

//PlayerTank constans
const wchar_t playerTankPresents = 'T';
const Direction::Directions startTankDirection = Direction::Directions::up;
const unsigned int actorStartXPosition = ((battleFieldWidth - strongHoldWidth) / 2) + strongHoldWidth + 2;
const unsigned int actorStartYPosition = battleFieldHeight - 1;
const unsigned int actorDurability = 3;

//Bullet
const wchar_t bulletPresent = ':';
const unsigned int bulletDurability = 1;



