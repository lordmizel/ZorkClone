#ifndef __Player__
#define __Player__

#include <string>
#include "Entity.h"
#include "Creature.h"

class Room;

class Player : public Creature {
public:
	Player(const std::string name, const std::string description, Room* room);
	~Player();
private:

};
#endif