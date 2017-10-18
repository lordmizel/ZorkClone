#include <iostream>
#include <string>
#include "MonsterCreator.h"
#include "Monster.h"
#include "Room.h"

using namespace std;


Monster::Monster(string name, string description, Room * room) : Creature(name, description, room)
{
	type = MONSTER;
	CreateMonster(name, description, description2);
}

Monster::~Monster()
{
}


