#ifndef __Monster__
#define __Monster__

#include <string>
#include "Entity.h"
#include "Creature.h"

class Room;

class Monster : public Creature {
public:
	Monster(const std::string name, const std::string description, Room* room, bool capturable);
	~Monster();

	void Look() const;
	void AssessHP() const;

	std::string description2;
	bool capturable = true;


private:

};
#endif