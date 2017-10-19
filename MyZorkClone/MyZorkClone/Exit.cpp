#include "Exit.h"
#include "Room.h"
#include <string>

using namespace std;




Exit::Exit(const string name, const string alternateName, const string description, Room* room, Room* destination) : Entity(name, description, (Entity*)room), alternateName(alternateName), destination(destination)
{
	type = EXIT;
}

Exit::Exit(const string name, const string alternateName, string description, Room * room, Room * destination, bool locked) : Entity(name, description, (Entity*)room), alternateName(alternateName), destination(destination), locked(locked)
{
	type = EXIT;
}

Exit::~Exit()
{
}
