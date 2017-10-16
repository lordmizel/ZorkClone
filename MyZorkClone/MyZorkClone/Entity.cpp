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
	if (containedIn != NULL) {
		containedIn->entitiesContained.remove(this);
	}
	if (newContainer != NULL) {
		newContainer->entitiesContained.push_back(this);
	}
	containedIn = newContainer;
}

//TODO: Entity finders