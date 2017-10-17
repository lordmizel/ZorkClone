#ifndef __NPC__
#define __NPC__

#include <string>
#include "Entity.h"
#include "Creature.h"

class Room;

class Monster : public Creature {
public:
	Monster(const std::string name, const std::string description, Room* room);
	~Monster();
private:

};
#endif