#include <iostream>
#include "Exit.h"
#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "Room.h"
#include "NpcInteractions.h"

using namespace std;

Player::Player(const string name, const string description, Room * room) : Creature(name, description, room) {
	type = PLAYER;
	maxHP = 3;
	currentHP = maxHP;
}

Player::~Player()
{
}

void Player::AssessHP() const
{
	if (currentHP == maxHP)
	{
		cout << "You're as healthy as you can be right now." << endl;
	}
	else if (currentHP > maxHP / 2)
	{
		cout << "You took some hits. Better be careful or this adventure will end before you know it." << endl;
	}
	else
	{
		cout << "Your stamina is about to run out. You'd better go get some medical treatment, and do it fast." << endl;
	}
	return;
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
	}

	cout << endl;
}

void Player::Look(const vector<string>& args) const
{
	if (args.size() > 1)
	{
		if (args[1] == "ME" || args[1] == "MYSELF")
		{
			cout << "You take a moment to look at yourself." << endl;
			cout << description << endl;
			AssessHP();
			return;
		}

		for (list<Entity*>::const_iterator it = containedIn->entitiesContained.begin(); it != containedIn->entitiesContained.cend(); ++it)
		{
			if ((*it)->name == args[1])
			{
				cout << "You see a " << (*it)->name << "." << endl;
				(*it)->Look();

				//Look for entities contained in item containers
				if ((*it)->type == ITEM) {
					for (list<Entity*>::const_iterator it2 = (*it)->entitiesContained.begin(); it2 != (*it)->entitiesContained.cend(); ++it2) {
						(*it2)->Look();
					}
				}
				return;
			}
		}
		for (list<Entity*>::const_iterator it = this->entitiesContained.begin(); it != this->entitiesContained.cend(); ++it)
		{
			if ((*it)->name == args[1])
			{
				cout << "You have a " << (*it)->name << " in your inventory." << endl;
				(*it)->Look();
				return;
			}
		}
		cout << "You don't see any " << args[1] << " around." << endl;
	}
	else
	{
		containedIn->Look();
	}
	return;
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
		if (Find("KEY", ITEM)) {
			cout << "You used the key to open the door." << endl;
			ChangeContainer(exit->destination);
			containedIn->Look();
			exit->locked = false;
			//TODO : Mirar de implementar un unlock
		}
		else {
			cout << "Seems like this door is locked." << endl;
		}
		
	}
	else {

		ChangeContainer(exit->destination);
		containedIn->Look();
		return true;
	}
}

bool Player::Attack(const vector<string>& args)
{
	if (containedIn->Find(args[1], MONSTER)) {
		cout << "You try to attack the monster without any plan and it goes just as well as you'd expect." << endl;
		cout << "Which means not well at all." << endl;
		currentHP -= 1;
		AssessHP();
		return false;
	}
	else if (containedIn->Find(args[1], NPC)) {
		AttackNPC(args[1], this);
		return false;
	}
	else {
		cout << "That's not something you can attack. So let's say you attack the air instead. :)" << endl;
	}
	return false;
}

bool Player::Talk(const vector<string>& args)
{
	if (containedIn->Find(args[1], MONSTER)) {
		cout << "Monsters aren't much for conversation." << endl;
		return false;
	}
	else if (containedIn->Find(args[1], NPC)) {
		TalkNPC(args[1], this);
		return false;
	}
	else {
		cout << "... What, you've got an imaginary friend now...?" << endl;
	}
	return false;
}

bool Player::Grab(const vector<string>& args)
{
	if (args.size() == 2) {
		Item* item = (Item*)containedIn->Find(args[1], ITEM);
		if (item == nullptr)
		{
			cout << args[1] << " is not an item you can grab, you nincompoop!" << endl;
		}
		else
		{
			cout << "You grab the " << args[1] << "." << endl;
			item->ChangeContainer(this);
			return true;
		}
	}
	else if (args.size() == 4) {
		Item* container = (Item*)containedIn->Find(args[3], ITEM);
		if (container == nullptr)
		{
			cout << "You see no " << args[3] << " around." << endl;
		}
		else 
		{
			Item* item = (Item*)container->Find(args[1], ITEM);
			if (item == nullptr) 
			{
				cout << "There's no " << args[1] << " in that " << args[3] << "." << endl;
			}
			else {
				item->ChangeContainer(this);
				return true;
			}
		}
	}
	return false;
}

bool Player::Drop(const vector<string>& args)
{
	Item* item = (Item*)Find(args[1], ITEM);
	if (item == nullptr)
	{
		cout << "You don't have any " << args[1] << "." << endl;
	}
	else
	{
		cout << "You drop the " << args[1] << "." << endl;
		item->ChangeContainer(this->containedIn);
		return true;
	}
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
