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
	std::list<Entity*> entitiesContained;

	Entity(const std::string &name, const std::string &description, Entity* containedIn);
	virtual ~Entity();

	virtual void Look() const;
	void ChangeContainer(Entity* newContainer);
	void FindAll(typeOfEntity type, std::list<Entity*>& listOfStuff) const;
	Entity* Find(const std::string& name, typeOfEntity type) const;
	Entity* Find(typeOfEntity type) const;

	std::string GetName() const;
	std::string GetDescription() const;
	Entity* ContainedIn() const;
	typeOfEntity GetType() const;

protected:
	std::string name = "";
	std::string description = "";
	Entity *containedIn = nullptr;
	typeOfEntity type;
	
};
#endif