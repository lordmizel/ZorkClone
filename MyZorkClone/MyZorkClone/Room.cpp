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
