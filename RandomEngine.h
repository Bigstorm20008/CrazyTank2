#pragma once

#include<random>
#include<ctime>
#include <memory>

class RandomEngine
{
public:
	
	~RandomEngine();

	static std::shared_ptr<RandomEngine> getInstance();
	const int getRandomInteger(const int& startDistance, const int& endDistance);
private:
	std::default_random_engine dre;
	RandomEngine();
	static std::shared_ptr<RandomEngine> instance;
};

