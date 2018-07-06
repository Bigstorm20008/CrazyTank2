#pragma once



//BattleFiled constants
const int battleFieldWidth = 20;
const int battleFieldHeight = 15;
const int wallsOnBattleField = 20;
const int startVectorSizeForEntities = 500;
const wchar_t emptySpace = ' ';

//WallBlock constants
const wchar_t wallBlockPresents[] = { 'X', 'H', 'I'};
const int wallBlockDurability = sizeof(wallBlockPresents) / sizeof(wchar_t);



