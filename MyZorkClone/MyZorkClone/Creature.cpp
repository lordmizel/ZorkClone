#include "Creature.h"

using namespace std;

Creature::Creature(const string name, const string description, Room * room) : Entity(name, description, (Entity*)room)
{
	type = CREATURE;
}

Creature::~Creature()
{
}
