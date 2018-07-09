#include "PlayerBullet.h"


PlayerBullet::PlayerBullet(const Point& position, const wchar_t& entityPresent, const unsigned int& durability, const Direction::Directions& direction)
	: Bullet(position,entityPresent,durability,direction)
{
	
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
