#include <iostream>
#include "Room.h"


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
