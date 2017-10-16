#include "Creature.h"

using namespace std;

Creature::Creature(const std::string name, const std::string description, Room * room) : Entity(name, description, (Entity*)room)
{
	type = CREATURE;
}

Creature::~Creature()
{
}
