#pragma once
#include<string>
#include <vector>

class Room
{
	friend class Dungeon;
	struct RoomLink
	{
		Room*room = nullptr;
		//std::vector<Room>room;
		std::string description="DEAD END";
	};
public:
	Room();
	~Room();
	const RoomLink&Room::GetNorth()const;
	const RoomLink&Room::GetWest()const;
	const RoomLink&Room::GetEast()const;
	const RoomLink&Room::GetSouth()const;
	const bool getEnemyInroom()const;
	std::string GetName();
	std::string GetDescription();
private:
	std::string Name;
	std::string Description;
	RoomLink North;
	RoomLink East;
	RoomLink South;
	RoomLink West;
	bool EnemyIn;
};