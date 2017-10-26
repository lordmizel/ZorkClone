#include <iostream>
#include "Creature.h"
#include "Monster.h"
#include "Room.h"
#include "Item.h"
#include "Npc.h"

using namespace std;


Room::Room(const string &name, const string &description) : Entity(name, description, nullptr)
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
		if ((*it)->GetType() == EXIT)
		{
			Exit* exit = (Exit*)*it;
			cout << exit->GetDescription() << endl;
		}
	}

	//Describe items
	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
	{
		if ((*it)->GetType() == ITEM)
		{
			Item* item = (Item*)*it;
			cout << "You see a " << item->GetName() << "." << endl;
		}
	}

	//Describe NPCs
	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
	{
		if ((*it)->GetType() == NPC)
		{
			Npc* npc = (Npc*)*it;
			cout << "You see " << npc->GetName() << " standing around." << endl;
		}
	}

	//Describe monsters
	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
	{
		if ((*it)->GetType() == MONSTER)
		{
			Monster* monster = (Monster*)*it;
			cout << "You see a " << monster->GetName() << " lurking nearby!" << endl;
		}
	}
}

Exit * Room::GetExit(const std::string &name)
{
	for (list<Entity*>::const_iterator it = entitiesContained.begin(); it != entitiesContained.cend(); ++it)
	{
		if ((*it)->GetType() == EXIT)
		{
			Exit* exit = (Exit*)*it;
			if (exit->GetName() == name || exit->GetAlternateName() == name)
			{
				return exit;
			}
		}
	}

	return nullptr;
}
