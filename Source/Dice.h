#pragma once
class Dice
{
public:
	Dice() = delete;
	Dice(int sides);
	
	int rollDice();
private:
	int sides = 0;
};