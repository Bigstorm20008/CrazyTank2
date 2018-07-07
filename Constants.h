#pragma once

#include "Direction.h"

//CrazyTanks constants
const int wallsOnBattleField = 80;
const int startVectorSizeForEntities = 500;

//PlayField constans
const int battleFieldWidth = 40;
const int battleFieldHeight = 20;
const wchar_t emptySpace = ' ';

//StrongHold constans
const int strongHoldWidth = 10;
const int strongHoldHeight = 4;


//WallBlock constants
const wchar_t wallBlockPresents[] = { 'X', 'H', 'I'};


//StrongHold constants
const wchar_t strongHoldBlocksPresents[] = { 'H', 'K', 'I' };

//PlayerTank constans
const wchar_t playerTankPresents = 'T';
const Direction::Directions startTankDirection = Direction::Directions::up;
const int startXPosition = ((battleFieldWidth - strongHoldWidth) / 2) + strongHoldWidth + 2;
const int startYPosition = battleFieldHeight - 1;



