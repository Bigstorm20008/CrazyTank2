#pragma once

class Point
{
public:
	explicit Point(int xPos, int yPos);
	explicit Point();
	virtual~Point();

	int xPosition;
	int yPosition;

	bool operator==(const Point& point)const;
	bool operator!=(const Point& point)const;
};

