#include "PlayerBullet.h"


PlayerBullet::PlayerBullet(const Point& startPostion, const Direction::Directions& direction, const wchar_t& bulletPresent)
{
	m_currentPosition = startPostion;
	m_direction = direction;
	m_presents = bulletPresent;
	m_durability = 1;
}


PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::doLogic(ConsoleGame& game)
{
	goToNextPositon(game);
}

void PlayerBullet::procesCollision(const Point& point, ConsoleGame& game)
{
	Entity* entity = game.getEntityAtPoint(point);
	if (entity)
	{
		entity->decreaseHealth();
		game.m_entitiesToDelete.push_back(this);
	}

	
}
