#pragma once

#include <iostream>
#include <vector>



//forward declaration
class Point;
#include "Point.h"

//forward declaration
class Entity;

#include "WallCreator.h"

#include "Constants.h"

class BattleField
{
public:
	explicit BattleField();
	virtual ~BattleField();

	void init(const int& width,const int& height);

	void print()const;

	const wchar_t& getValueInPosition(const int& x, const int& y)const;
	void setValueInPosition(const int& x, const int& y, const wchar_t& value);

	const int& getWidth()const;
	const int& getHeight()const;
	std::vector<std::vector<wchar_t>>& getPlayField();

	bool isFreePoint(const Point& point)const;
	bool isValidPoint(const Point& point)const;
private:
	std::vector<std::vector<wchar_t>> m_battleField;

	int m_width;
	int m_height;

};

