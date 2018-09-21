#include "Dungeon.h"
#include"Room.h"

void Dungeon::creat()
{
	//rooms = new Room[8];
	//create 5 empty rooms 

	rooms = { 8,Room()};

	Room&room1 = rooms[0];
	Room&room2 = rooms[1];
	Room&room3 = rooms[2];
	Room&room4 = rooms[3];
	Room&room5 = rooms[4];
	Room&room6 = rooms[5];
	Room&room7 = rooms[6];
	Room&room8 = rooms[7];

	room1.Name = "Room1";
	room1.Description = "the room is dark but you still know where you are";
	room1.South.description = "a room South of you";
	room1.South.room = &room2;
	room1.West.description = "a room West of you";
	room1.West.room = &room4;

	room2.Name = "Room2";
	room2.Description = "a dull lifeless room";
	room2.West.description = "a room West of you";
	room2.West.room = &room3;
	room2.North.description = "a room North of you";
	room2.North.room = &room1;

	room3.Name = "Room3";
	room3.Description = "a large room who knows what it used to be , bats hang from the celing ";
	room3.EnemyIn = true;
	room3.North.description = "a room North of you";
	room3.North.room = &room4;
	room3.East.description = "a room East of you";
	room3.East.room = &room2;
	room3.West.description = "a room West of you";
	room3.West.room = &room5;
	room3.South.description = "a room south of you";
	room3.South.room = &room7;

	room4.Name = "Room4";
	room4.Description = "the room seems to be an old banquet hall";
	room4.East.description = "a room East of you";
	room4.East.room = &room1;
	room4.South.description = "a room souht of you";
	room4.South.room = &room3;

	room5.Name = "Room5";
	room5.Description = "a kitchen old pots and pans lay scattered on the floor";
	room5.North.description = "a room North of you";
	room5.North.room = &room6;
	room5.East.description = "a room East of you";
	room5.East.room= &room3;


	room6.Name = "Room6";
	room6.Description = "this room must have been the pantre";
	room6.South.description = "a room souht of you";
	room6.South.room = &room5;

	room7.Name = "Room7";
	room7.Description = "the passageway leads to a large wooden door hanging on its broken hindges";
	room7.South.description = "a room South of you";
	room7.South.room = &room8;
	room7.North.description = "a room North of you";
	room7.North.room = &room3;

	room8.Name = "Room8";
	room8.Description = "the floor is covered with human sceletons who knows what killed these men";
	room8.North.description = "a room North of you";
	room8.North.room = &room7;


}
Room*Dungeon::GetRoom(int idx)
{
	return&rooms[idx];
}

Dungeon::~Dungeon()
{
	
	
}