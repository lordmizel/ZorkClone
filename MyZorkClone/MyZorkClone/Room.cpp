#include <iostream>
#include "Creature.h"
#include "Monster.h"
#include "Room.h"
#include "Item.h"
#include "Npc.h"


using namespace std;

Room::Room(const string name, const string description) : Entity(name, description, nullptr)
{
	type = ROOM;
}

Room::~Room(){
}

void Room::Look() const
{
	cout << description << endl;

	//Describe exits
	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
	{
		if ((*it)->type == EXIT)
		{
			Exit* exit = (Exit*)*it;
			cout << exit->description << endl;
		}
	}

	//Describe items
	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
	{
		if ((*it)->type == ITEM)
		{
			Item* item = (Item*)*it;
			cout << "You see a " << item->name << "." << endl;
		}
	}

	//Describe NPCs
	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
	{
		if ((*it)->type == NPC)
		{
			Npc* npc = (Npc*)*it;
			cout << npc->name << " is standing around." << endl;
		}
	}

	//Describe monsters
	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
	{
		if ((*it)->type == MONSTER)
		{
			Monster* monster = (Monster*)*it;
			cout << "WATCH OUT! You see a " << monster->name << " lurking nearby!" << endl;
		}
	}
}

Exit * Room::GetExit(const std::string name)
{
	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
	{
		if ((*it)->type == EXIT)
		{
			Exit* exit = (Exit*)*it;
			if (exit->name == name || exit->alternateName == name)
			{
				return exit;
			}
		}
	}

	return nullptr;
}
