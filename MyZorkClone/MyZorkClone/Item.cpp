#include "Item.h"
#include "Entity.h"

using namespace std;

Item::Item(const std::string name, const std::string description, Entity* containedIn) : Entity(name, description, (Entity*)containedIn)
{
	type = ITEM;
}

Item::~Item()
{
}
