#include "Exit.h"
#include "Room.h"
#include "Item.h"

using namespace std;


Exit::Exit(const string &name, const string &alternateName, const string &description, Room* room, Room* destination) : Entity(name, description, (Entity*)room), alternateName(alternateName), destination(destination)
{
	type = EXIT;
}

Exit::Exit(const string &name, const string &alternateName, const string &description, Room * room, Room * destination, bool locked, Item* key) : Entity(name, description, (Entity*)room), alternateName(alternateName), destination(destination), locked(locked), key(key)
{
	type = EXIT;
}

Exit::~Exit()
{
}

void Exit::LockState(bool lock)
{
	locked = lock;
}

Room * Exit::GetDestination() const
{
	return destination;
}

std::string Exit::GetAlternateName() const
{
	return alternateName;
}

bool Exit::IsLocked() const
{
	return locked;
}

Item * Exit::GetAssociatedKey() const
{
	return key;
}
