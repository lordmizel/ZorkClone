#ifndef __Monster__
#define __Monster__

#include "Creature.h"

class Room;

class Monster : public Creature {
public:
	Monster(std::string name, std::string description, Room* room, bool capturable);
	~Monster();

	void Look() const;
	void AssessHP() const;

	bool IsCapturable() const;
private:
	std::string description2;
	bool capturable = true;
};
#endif