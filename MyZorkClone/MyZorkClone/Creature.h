#ifndef __Creature__
#define __Creature__

#include "Entity.h"
#include "Room.h"

class Creature : public Entity {
public:

	Creature(const std::string name, const std::string description, Room* room);
	~Creature();

public:
};

#endif