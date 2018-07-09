#pragma once

#include <Windows.h>
#include <iostream>

#include "GameState.h"



class MenuState :
	public GameState
{
public:
	friend class CrazyTank;
	
	virtual ~MenuState();

	void update()override;
	void render()override;

private:
	explicit MenuState();
};

