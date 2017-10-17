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

void Player::Inventory() const
{
	list<Entity*> items;
	FindAll(ITEM, items);

	cout << "You take a moment to stop and keep track of the stuff you're carrying." << endl;

	if (items.size() == 0)
	{
		cout << "Alas, you don't have anything with you right now." << endl;
		return;
	}

	for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
	{
		cout << "You have a " << (*it)->name << "." << endl;
		cout << (*it)->description << endl;
	}

	cout << "\n";
}

/*void Player::Look(const vector<string>& args) const
{
}

void Player::Escape(const vector<string>& args)
{
}

bool Player::Go(const vector<string>& args)
{
	return false;
}

bool Player::Attack(const vector<string>& args)
{
	return false;
}

bool Player::Grab(const vector<string>& args)
{
	return false;
}

bool Player::Drop(const vector<string>& args)
{
	return false;
}

bool Player::Use(const vector<string>& args)
{
	return false;
}*/

void Player::Tick()
{
}

void Player::Die()
{
}
