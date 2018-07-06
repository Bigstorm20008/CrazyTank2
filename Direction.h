#pragma once
class Direction
{
public:
	explicit Direction();
	virtual ~Direction();
	enum Directions {up, down, left, right} m_direction;
};

