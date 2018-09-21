#include "EnemyType.h"
#include "Enemy.h"
#include <jsoncons/json.hpp>

EnemyType::EnemyType(int hp, int atk, int arm, std::string desc, std::string render,std::string dead)
{
	health = hp;
	attack_rating = atk;
	armour_rating = arm;
	description_str = desc;
	render_str = render;
}

Enemy* EnemyType::createEnemy()
{
	return new Enemy(*this);
}

int EnemyType::getHealth()const
{
	return health;
}

int EnemyType::getAttackRating()const
{
	return attack_rating;
}

int EnemyType::getArmourRating()const
{
	return armour_rating;
}
const std::string& EnemyType::getDescriptionString()const
{
	return description_str;
}

const std::string& EnemyType::getRenderString()const
{
	return render_str;
}
const std::string& EnemyType::getAttackString()const
{
	return attack_str;
}

void EnemyType::load()
{
	using jsoncons::json;
	std::ifstream
		is("..\\..\\Resources\\Data\\Enemies.json");
	json enemies;
	is >> enemies;
	for (const auto& type : enemies.members())
	{
		const auto& name = type.name();
		const auto& data = type.value();
		auto attack = data["attack"].as_cstring();
		auto health = data["health"].as_int();
		auto damage = data["damage"].as_int();
		auto armour = data["armour"].as_int();
		auto ascii = data["model"].as_string();
		auto description = data["description"].as_string();
		auto dead = data["dead"].as_string();
		std::ifstream model("..\\..\\Resources\\ASCII\\"
			+ ascii);
		std::string str((
			std::istreambuf_iterator<char>(model)),
			std::istreambuf_iterator<char>());
		enemy_types.push_back(
			EnemyType(health,
				damage, armour, description, str,dead));
	}
}
std::vector<EnemyType> EnemyType::enemy_types;
