#pragma once
class Action
{
public:

	explicit Action();
	~Action();

	enum Actions
	{
		MoveForward,
		MoveBack,
		MoveRight,
		MoveLeft,
		Fire
	} action;
};

