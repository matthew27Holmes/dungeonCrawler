#pragma once
#include <vector>
class Room;
class Dungeon
{
public:
	Dungeon() = default;
	~Dungeon();
	void creat();
	Room*GetRoom(int idx);
private:
	//Room*rooms = nullptr;
	std::vector<Room> rooms;
};

