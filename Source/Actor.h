#pragma once
#include "GameObject.h"

class Actor :public GameObject
{
public: 
	Actor() = default;
	~Actor() = default;
	int getHealth()const;
	int getArmour()const;
	int getAttack()const;

	bool isAlive()const;

	virtual std::string getHealthAsString()const;

	virtual int attack(Actor*obj)const;
	virtual int defend(int dmg);

protected:
	int health = 100;
	int armour_rating = 10;
	int attack_rating = 3;
};