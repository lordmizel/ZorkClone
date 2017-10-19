#ifndef __Entity__
#define __Entity__

#include <list>
#include <string>

enum typeOfEntity {
	ENTITY,
	ROOM,
	EXIT,
	CREATURE,
	NPC,
	MONSTER,
	PLAYER,
	ITEM
};

class Entity {
public:
	std::string name = "";
	std::string description = "";
	Entity *containedIn = nullptr;
	typeOfEntity type;
	std::list<Entity*> entitiesContained;

	Entity(const std::string name, const std::string description, Entity* containedIn);
	virtual ~Entity();
	virtual void Look() const;
	void ChangeContainer(Entity* newContainer);

	void FindAll(typeOfEntity type, std::list<Entity*>& listOfStuff) const;

private:

};
#endif