#pragma once
#include <Engine/Sprite.h>
#include <string>
#include "Actor.h"
#include "Inventory.h"
class Room;
namespace ASGE {
	class Renderer;
	class Sprite;
}

class Player:public Actor
{
public:

	enum class PlayerClass
	{
		BARBARIAN,
		ROGUE,
		WIZARD
	};

	Player(PlayerClass c);
	~Player() = default;

	void loadAvatar(std::shared_ptr<ASGE::Renderer> renderer);
	ASGE::Sprite* getAvatar();

	int getXP() const;
	int getStrength() const;
	int getDexterity() const;
	int getIntellect() const;
	int getLuck() const;
	int getMana() const;

	Room* GetRoom()const;
	void  setRoom(Room*rm);
	std::string GetDescription()const;
	std::string getHealthAsString() const;
	std::string getManaAsString() const;
	std::string getRenderString()const ;
	std::string getInventoryAsString()const;
	//int changeAvatar();
private:
	PlayerClass player_class;
	ASGE::Sprite* avatar = nullptr;
	Room* room =nullptr;
	std::unique_ptr<Inventory>inventory = nullptr;

	int health = 100;
	int experience = 0;
	int strength = 0;
	int dexterity = 0;
	int intelligence = 0;
	int luck = 0;
	int mana = 0;
};