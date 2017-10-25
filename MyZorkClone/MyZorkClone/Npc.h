#ifndef __NPC__
#define __NPC__

#include <string>
#include "Entity.h"
#include "Creature.h"

class Room;

class Npc : public Creature {
public:
	Npc(const std::string &name, const std::string &description, Room* room);
	~Npc();

private:

};
#endif