#include <iostream>
#include <string>
#include "MonsterCreator.h"
#include "Monster.h"
#include "Room.h"

using namespace std;


Monster::Monster(string name, string description, Room * room, bool capturable) : Creature(name, description, room), capturable(capturable)
{
	type = MONSTER;
	maxHP = 3;
	currentHP = maxHP;
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

void Monster::AssessHP() const
{
	if (currentHP <= 0) {
		cout << name << " gives out a cry and falls defeated to the ground!!" << endl;
	} 
	else if (currentHP == maxHP)
	{
		cout << name << " is healthy and ready for battle!" << endl;
	}
	else if (currentHP > maxHP / 2)
	{
		cout << name << " is injured but can still go on!" << endl;
	}
	else
	{
		cout << name << " looks like is about to faint!" << endl;
	}
}
