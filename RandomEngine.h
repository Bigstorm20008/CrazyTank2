#pragma once

#include<random>
#include<ctime>
#include <memory>

#include "Direction.h"

class RandomEngine
{
public:
	
	~RandomEngine();

	static std::shared_ptr<RandomEngine> getInstance();
	const int getRandomInteger(const int& startDistance, const int& endDistance);
	const Direction::Directions getRandomDirection();
private:
	std::default_random_engine dre;
	RandomEngine();
	static std::shared_ptr<RandomEngine> instance;
};

