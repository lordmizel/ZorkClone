#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature(const string &name, const string &description, Room * room) : Entity(name, description, (Entity*)room)
{
	type = CREATURE;
}

Creature::~Creature()
{
}

void Creature::Look() const
{
	cout << description << endl;
}

void Creature::Hurt()
{
	currentHP--;
}

int Creature::GetMaxHP() const
{
	return maxHP;
}

int Creature::GetCurrentHP() const
{
	return currentHP;
}

void Creature::SetMaxHP(int &value)
{
	maxHP = value;
}

void Creature::SetCurrentHP(int &value)
{
	currentHP = value;
}
