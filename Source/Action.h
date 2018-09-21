#pragma once
#include<string>
#include<atomic>

enum class GameAction
{
	INVALID = -1,
	NONE=0,
	ATTACK,
	NORTH,
	EAST,
	WEST,
	SOUTH,
	INVENTORY
	
};
enum class Direction
{
	NORTH,
	EAST,
	WEST,
	SOUTH

};

namespace ActionStringLiterals
{
	const std::string attack = "ATTACK";
	const std::string north = "NORTH";
	const std::string east = "EAST";
	const std::string west = "WEST";
	const std::string south = "SOUTH";
	const std::string inventory = "INVENTORY";

}
extern std::atomic<GameAction> game_action;

