#include <iostream>
#include "Exit.h"
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

	cout << endl;
}

void Player::Look(const vector<string>& args) const
{
	if (args.size() > 1)
	{
		for (list<Entity*>::const_iterator it = containedIn->entitiesContained.begin(); it != containedIn->entitiesContained.cend(); ++it)
		{
			if ((*it)->name == args[1] /*|| ((*it)->type == EXIT && args[1] == ((Exit*)(*it))->GetNameFrom((Room*)containedIn)))*/)
			{
				(*it)->Look();
				return;
			}
		}

		if (args[1] == "ME" || args[1] == "MYSELF")
		{
			cout << "You take a moment to look at yourself." << endl;
			cout << description << endl;
			if (hp == MAX_PLAYER_HP)
			{
				cout << "You're as healthy as you can be right now." << endl;
			}
			else if (hp > MAX_PLAYER_HP / 2)
			{
				cout << "You took some hits. Better be careful or this adventure will end before you know it." << endl;
			}
			else
			{
				cout << "Your stamina is about to run out. You'd better go get some medical treatment, and do it fast." << endl;
			}
		}
	}
	else
	{
		containedIn->Look();
	}
}

void Player::Escape(const vector<string>& args)
{
}

bool Player::Go(const vector<string>& args)
{
	Room* presentRoom = (Room*)containedIn;
	Exit* exit = presentRoom->GetExit(args[1]);
	if (exit == nullptr)
	{
		cout << "That's not a place you can GO to." << endl;
		return false;
	}
	if (exit->locked == true)
	{
		cout << "Seems like this door is locked." << endl;
		return false;
	}
	ChangeContainer(exit->destination);
	containedIn->Look();
	return true;
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
}

void Player::Tick()
{
}

void Player::Die()
{
}
