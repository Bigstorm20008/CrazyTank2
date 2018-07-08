#pragma once

#include <Windows.h>
#include <iostream>

#include "GameState.h"



class MenuState :
	public GameState
{
public:
	explicit MenuState();
	virtual ~MenuState();

	void update()override;
	void render()override;
};

