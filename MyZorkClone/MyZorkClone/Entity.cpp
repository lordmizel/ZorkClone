#include <iostream>
#include <string>
#include "Entity.h"

using namespace std;


Entity::Entity(const string name, const string description, Entity* containedIn = nullptr) : name(name), description(description), containedIn(containedIn) {
	type = ENTITY;
	if (containedIn != nullptr) {
		containedIn->entitiesContained.push_back(this);
	}
}


Entity::~Entity(){
}


void Entity::Look() const{
	cout << description << endl;
}


void Entity::ChangeContainer(Entity* newContainer){
	if (containedIn != NULL) 
	{
		containedIn->entitiesContained.remove(this);
	}
	if (newContainer != NULL) 
	{
		newContainer->entitiesContained.push_back(this);
	}
	containedIn = newContainer;
}

void Entity::FindAll(typeOfEntity type, list<Entity*>& listOfStuff) const
{
	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
	{
		if ((*it)->type == type)
			listOfStuff.push_back(*it);
	}
}

//TODO: Entity finders