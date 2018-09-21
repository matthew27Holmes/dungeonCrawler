#include "Enemy.h"
#include "EnemyType.h"
#include <sstream>
Enemy::Enemy(EnemyType& t) :
	type(t)
{
	health = t.getHealth();
	attack_rating = t.getAttackRating();
	armour_rating = t.getArmourRating();
}
std::string Enemy::getRenderString() const
{
	return type.getRenderString();
}
std::string Enemy::GetDescription() const
{
	return type.getDescriptionString();
}
std::string Enemy::getHealthAsString() const
{
	std::stringstream ss;
	for (int i = 0; i < health; i += 5)
	{
		ss << '#';
	}
	return ss.str().c_str();
}
int Enemy::getHealth() const
{
	return health;
}