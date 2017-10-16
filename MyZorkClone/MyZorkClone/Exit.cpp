#include "Exit.h"
#include "Room.h"
#include <string>

using namespace std;




Exit::Exit(const std::string name, const std::string description, Room* room, Room* destination) : Entity(name, description, (Entity*)room), destination(destination)
{
	type = EXIT;
}

Exit::~Exit()
{
}
