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
	this->name = name;
	this->description = description;
	this->description2 = description2;
}

Monster::~Monster()
{
}

void Monster::Look() const
{
	cout << description << endl;
	cout << description2 << endl;
}
