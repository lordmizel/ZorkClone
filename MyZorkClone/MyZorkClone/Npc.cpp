#include <iostream>
#include "Npc.h"
#include "Room.h"

using namespace std;

Npc::Npc(const string name, const string description, Room * room) : Creature(name, description, room)
{
	type = NPC;
}

Npc::~Npc()
{
}
