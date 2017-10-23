#ifndef __Item__
#define __Item__

#include "Entity.h"
#include "Room.h"

class Item : public Entity {
public:

	Item(const std::string name, const std::string description, Entity* containedIn);
	Item(const std::string name, const std::string description, Entity* containedIn, bool isContainer);
	Item(const std::string name, const std::string description, Entity* containedIn, bool isContainer, bool grabbable);
	~Item();

	void Look();

	bool isContainer = false;
	bool grabbable = true;
public:
};

#endif