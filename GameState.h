#pragma once


class GameState
{
public:
	explicit GameState();
	virtual ~GameState();

	virtual void update() = 0;
	virtual void render() = 0;
protected:
	bool m_isVisible;
};

