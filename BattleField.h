#pragma once

#include <iostream>
#include <vector>



//forward declaration
class Point;
#include "Point.h"

#include "Constants.h"

class BattleField
{
public:
	friend class ConsoleGame;
	friend class CrazyTank;

	~BattleField();

	const wchar_t& getValueInPosition(const unsigned int& x, const unsigned int& y)const;
	void setValueInPosition(const unsigned int& x, const unsigned int& y, const wchar_t& value);

	const unsigned int& getWidth()const;
	const unsigned int& getHeight()const;
	std::vector<std::vector<wchar_t>>& getPlayField();

	bool isFreePoint(const Point& point)const;
	bool isValidPoint(const Point& point)const;
private:
	explicit BattleField();

	void init(const int& width, const int& height);
	void print()const;

	std::vector<std::vector<wchar_t>> m_battleField;

	unsigned int m_width;
	unsigned int m_height;

};

