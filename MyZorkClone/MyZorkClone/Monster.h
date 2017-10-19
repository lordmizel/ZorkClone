#ifndef __Monster__
#define __Monster__

#include <string>
#include "Entity.h"
#include "Creature.h"

class Room;

class Monster : public Creature {
public:
	Monster(const std::string name, const std::string description, Room* room);
	~Monster();

	//void Look() const;

	std::string description2;


private:

};
#endif