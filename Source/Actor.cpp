#include "Actor.h"
#include"Dice.h"

bool Actor::isAlive()const
{
	if (health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Actor::getHealth() const
{
	return health;
}
int Actor::getAttack()const
{
	return attack_rating;
}

int Actor::getArmour()const
{
	return armour_rating;
}

int Actor::attack(Actor*obj)const
{
	Dice Dice(attack_rating);
	auto dmg = Dice.rollDice();
	dmg*=attack_rating;
	obj->defend(dmg);
	return dmg;
}

int Actor::defend(int dmg)
{
	dmg -= armour_rating;
	if (dmg > 0)
	{
		health -= dmg;
	}
	else
	{
		health += dmg;
	}
	return dmg;
}

std::string Actor::getHealthAsString()const
{
	return std::string("100%");
}

