#include <iostream>
#include "Monster.h"
#include "Room.h"

Monster::Monster(const std::string name, const std::string description, Room * room) : Creature(name, description, room)
{
	type = MONSTER;
}

Monster::~Monster()
{
}
