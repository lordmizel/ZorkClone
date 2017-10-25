#include <iostream>
#include "Item.h"
#include "Entity.h"

using namespace std;


Item::Item(const std::string name, const std::string description, Entity* containedIn) : Entity(name, description, (Entity*)containedIn)
{
	type = ITEM;
}

Item::Item(const std::string name, const std::string description, Entity * containedIn, bool isContainer) : Entity(name, description, (Entity*)containedIn), isContainer(isContainer)
{
	type = ITEM;
}

Item::Item(const std::string name, const std::string description, Entity * containedIn, bool isContainer, bool grabbable) : Entity(name, description, (Entity*)containedIn), isContainer(isContainer), grabbable(grabbable)
{
	type = ITEM;
}

Item::~Item()
{
}

void Item::Look() const
{
	cout << description << endl;

	if (isContainer == true) {
		for (list<Entity*>::const_iterator it = this->entitiesContained.begin(); it != this->entitiesContained.cend(); ++it) {
			cout << "There's a " << (*it)->GetName() << " in the " << name << "." << endl;
		}
	}
}
