#include <iostream>
#include <string>
#include "Entity.h"

using namespace std;


Entity::Entity(const string &name, const string &description, Entity* containedIn = nullptr) : name(name), description(description), containedIn(containedIn) {
	type = ENTITY;
	if (containedIn != nullptr) {
		containedIn->entitiesContained.push_back(this);
	}
}

Entity::~Entity(){
	for (list<Entity*>::reverse_iterator it = entitiesContained.rbegin(); it != entitiesContained.rend(); ++it)
	{
		if ((*it) != nullptr) {
			delete *it;
			(*it) = nullptr;
		}
	}
}

void Entity::Look() const{
	cout << description << endl;
}

void Entity::ChangeContainer(Entity* newContainer){
	if (containedIn != nullptr) 
	{
		containedIn->entitiesContained.remove(this);
	}
	if (newContainer != nullptr) 
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

Entity * Entity::Find(const std::string & name, typeOfEntity type) const
{
	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
	{
		if ((*it)->type == type)
		{
			if ((*it)->name == name)
				return *it;
		}
	}

	return nullptr;
}

Entity * Entity::Find(typeOfEntity type) const
{
	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
	{
		if ((*it)->type == type)
		{
			return *it;
		}
	}
	return nullptr;
}

std::string Entity::GetName() const
{
	return name;
}

std::string Entity::GetDescription() const
{
	return description;
}

Entity * Entity::ContainedIn() const
{
	return containedIn;
}

typeOfEntity Entity::GetType() const
{
	return type;
}

//std::list<Entity*> Entity::GetEntitiesContined() const
//{
//	return entitiesContained;
//}

//Entity * Entity::Find(typeOfEntity type) const
//{
//	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
//	{
//		if ((*it)->type == type)
//			return *it;
//	}
//
//	return nullptr;
//}

//TODO: Entity finders