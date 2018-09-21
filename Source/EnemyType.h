#pragma once
#include<vector>
#include<string>
class Enemy;
class EnemyType
{
public:
	EnemyType(int hp, int atk, int arm, std::string desc, std::string render,std::string dead);
	~EnemyType() = default;
	int getHealth()const;
	int getArmourRating()const;
	int getAttackRating()const;

	const std::string& getAttackString()const;
	const std::string& getRenderString() const;
	const std::string& getDescriptionString()const;

	Enemy* createEnemy();
	static void load();
private:
	int health = 0;
	int armour_rating = 0;
	int attack_rating = 0;
	std::string attack_str = "say what?";
	std::string render_str = "O_o";
	std::string description_str = "I am an enemy";
	std::string dead_str = "dead";
public:
	static std::vector<EnemyType> enemy_types;
};