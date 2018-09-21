#include "Dice.h"
#include<random>
Dice::Dice(int sideCount)
	:sides(sideCount)
{
	return;
}
int Dice::rollDice()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int>random(1, sides);
	return random(mt);
}