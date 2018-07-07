#include "BattleField.h"


BattleField::BattleField()
{
	
}


BattleField::~BattleField()
{
	
}

void BattleField::init(const int& width, const int& height)
{	
	m_width = width;
	m_height = height;

	m_battleField.reserve(height);
	while (m_battleField.size() < m_battleField.capacity())
	{
		std::vector<wchar_t> row(width, emptySpace);
		m_battleField.push_back(row);
	}
}


void BattleField::print()const
{
	for (auto& row : m_battleField)
	{
		for (auto& elem : row)
		{
			std::wcout << elem;
		}
		std::wcout << std::endl;
	}	
}

const wchar_t& BattleField::getValueInPosition(const int& x, const int& y)const
{
	return m_battleField[y][x];
}

void BattleField::setValueInPosition(const int& x, const int& y, const wchar_t& value)
{
	m_battleField[y][x] = value;
}





const int& BattleField::getWidth()const
{
	return m_width;
}

const int& BattleField::getHeight()const
{
	return m_height;
}

bool BattleField::isFreePoint(const Point& point)const
{
	return (m_battleField[point.yPosition][point.xPosition] == emptySpace);
}

bool BattleField::isValidPoint(const Point& point)const
{
	if ((point.xPosition < 0) || (point.xPosition > (m_width-1)) || (point.yPosition < 0) ||(point.yPosition > (m_height-1)))
	{
		return false;
	}
	else
		return true;
}


std::vector<std::vector<wchar_t>>& BattleField::getPlayField()
{
	return m_battleField;
}
