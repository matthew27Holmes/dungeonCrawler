#include "Room.h"
Room::Room()
{

}
Room::~Room()
{

}
std::string Room::GetName()
{
	return Name;
}
std::string Room::GetDescription()
{
	return Description;
}
const bool Room::getEnemyInroom()const
{
	return EnemyIn;
}
const Room::RoomLink& Room::GetNorth()const
{
	return North;
}
const Room::RoomLink& Room::GetWest()const
{
	return West;
}

const Room::RoomLink& Room::GetEast()const
{
	return East;
}
const Room::RoomLink& Room::GetSouth()const
{
	return South;
}