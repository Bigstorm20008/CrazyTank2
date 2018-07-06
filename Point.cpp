#include "Point.h"


Point::Point(int xPos, int yPos)
{
	xPosition = xPos;
	yPosition = yPos;
}

Point::Point()
{
	xPosition = 0;
	yPosition = 0;
}


Point::~Point()
{
}

bool Point::operator==(const Point& point) const
{
	return ((this->xPosition == point.xPosition) && (this->yPosition == point.yPosition));
}

bool Point::operator!=(const Point& point)const
{
	if (*this == point)
		return false;
	else
		return true;

}
