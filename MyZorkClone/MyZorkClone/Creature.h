#ifndef __Creature__
#define __Creature__

#include "Entity.h"

class Room;

class Creature : public Entity {
public:

	Creature(const std::string &name, const std::string &description, Room* room);
	~Creature();

	void Look() const;

	void Hurt();

	int GetMaxHP() const;
	int GetCurrentHP() const;
	void SetMaxHP(int &value);
	void SetCurrentHP(int &value);
	
protected:
	int maxHP;
	int currentHP;
};

#endif