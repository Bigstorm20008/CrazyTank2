#include "RandomEngine.h"


std::shared_ptr<RandomEngine> RandomEngine::instance = nullptr;

RandomEngine::RandomEngine() :dre(std::default_random_engine(static_cast<unsigned int>(time(0))))
{
}


RandomEngine::~RandomEngine()
{
}

std::shared_ptr<RandomEngine> RandomEngine::getInstance()
{

	if (instance == nullptr)
	{
		instance.reset(new RandomEngine);
	}
	return instance;
}

const int RandomEngine::getRandomInteger(const int& startDistance, const int& endDistance)
{
	std::uniform_int_distribution<int> widthDistance(startDistance, endDistance);
	return widthDistance(dre);
}

const Direction::Directions RandomEngine::getRandomDirection()
{
	unsigned int directionSize = sizeof(Direction::Directions);
	std::uniform_int_distribution<int> distance(0, directionSize);

	Direction::Directions direction = static_cast<Direction::Directions>(distance(dre));
	return direction;
}
