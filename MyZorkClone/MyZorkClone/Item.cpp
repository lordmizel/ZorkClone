#include "Item.h"

using namespace std;

Item::Item(const std::string name, const std::string description, Room* room) : Entity(name, description, (Entity*)room)
{
	type = ITEM;
}

Item::~Item()
{
}
