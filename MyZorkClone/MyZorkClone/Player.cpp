#include <iostream>
#include "Player.h"
#include "Room.h"

using namespace std;

Player::Player(const string name, const string description, Room * room) : Creature(name, description, room) {
	type = ITEM;
}

Player::~Player()
{
}
