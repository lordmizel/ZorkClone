#include <iostream>
#include "Globals.h"
#include "Exit.h"
#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "Room.h"
#include "NpcInteractions.h"
#include "ItemUsage.h"

using namespace std;


Player::Player(const string name, const string description, Room * room) : Creature(name, description, room) 
{
	type = PLAYER;
	maxHP = 3;
	currentHP = maxHP;
}

Player::~Player()
{
}

void Player::AssessHP() const
{
	if (currentHP <= 0) 
	{
		GAME_OVER = true;
		cout << "You're too beat up to go on. Looks like your adventure ends here. :(" << endl;
		cout << "=========" << "GAME OVER" << "=========" << endl << endl;
		cout << "Type QUIT to exit game." << endl;
		return;
	}

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
		cout << "You have a " << (*it)->GetName() << "." << endl;
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

		//Is the entity in the room?
		for (list<Entity*>::iterator it = containedIn->entitiesContained.begin(); it != containedIn->entitiesContained.cend(); ++it)
		{
			if ((*it)->GetName() == args[1])
			{
				(*it)->Look();
				return;
			}
		}

		//Is the entity in the player's inventory?
		for (list<Entity*>::const_iterator it = this->entitiesContained.begin(); it != this->entitiesContained.cend(); ++it)
		{
			if ((*it)->GetName() == args[1])
			{
				cout << "You have a " << (*it)->GetName() << " in your inventory." << endl;
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
	if (exit->IsLocked() == true)
	{
		if (Find("KEY", ITEM)) 
		{
			cout << "You used the key to open the door." << endl;
			ChangeContainer(exit->GetDestination());
			containedIn->Look();
			exit->LockState(false);
		}
		else 
		{
			cout << "Seems like this door is locked." << endl;
			return false;
		}
	}
	else 
	{
		ChangeContainer(exit->GetDestination());
		containedIn->Look();
	}
	return true;
}

bool Player::Attack(const vector<string>& args)
{
	if (containedIn->Find(args[1], MONSTER)) 
	{
		cout << "You try to attack the monster without any plan and it goes just as well as you'd expect." << endl;
		cout << "Which means not well at all." << endl;
		currentHP -= 1;
		AssessHP();
	}
	else if (containedIn->Find(args[1], NPC)) 
	{
		AttackNPC(args[1], this);
		return true;
	}
	else {
		cout << "That's not something you can attack. So let's say you attack the air instead. :)" << endl;
	}
	return false;
}

bool Player::Talk(const vector<string>& args)
{
	if (containedIn->Find(args[1], MONSTER)) 
	{
		cout << "Monsters aren't much for conversation." << endl;
	}
	else if (containedIn->Find(args[1], NPC)) 
	{
		TalkNPC(args[1], this);
		return true;
	}
	else 
	{
		cout << "... What, you've got an imaginary friend now...?" << endl;
	}
	return false;
}

bool Player::Grab(const vector<string>& args)
{
	if (args.size() == 2) 
	{
		Item* item = (Item*)containedIn->Find(args[1], ITEM);
		if (item == nullptr)
		{
			cout << "Where is this " << args[1] << " you're talking about?" << endl;
		}
		else
		{
			if (item->IsGrabbable()) 
			{
				cout << "You grab the " << args[1] << "." << endl;
				item->ChangeContainer(this);
				return true;
			}
			else 
			{
				cout << "You can't just go around carrying that thing, you nincompoop!" << endl;
			}
		}
	}
	else if (args.size() == 4) 
	{
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
				if (item->IsGrabbable()) 
				{
					cout << "You grab the " << args[1] << "." << endl;
					item->ChangeContainer(this);
					return true;
				}
				else 
				{
					cout << "You can't just go around carrying that thing, you nincompoop!" << endl;
				}
			}
		}
	}
	return false;
}

bool Player::Drop(const vector<string>& args) const
{
	Item* item = (Item*)Find(args[1], ITEM);
	if (item == nullptr)
	{
		cout << "You don't have any " << args[1] << "." << endl;
	}
	else if (args[1] == "CAPSULE") 
	{
		cout << "A true Zorkemon master will never drop his capsules!" << endl;
	}
	else
	{
		cout << "You drop the " << args[1] << "." << endl;
		item->ChangeContainer(this->containedIn);
		return true;
	}
	return false;
}

bool Player::Put(const vector<string>& args) const
{
	Entity* item = Find(args[1], ITEM);
	if (item == nullptr) 
	{
		cout << "You're not carrying any " << args[1] << "." << endl;
		return false;
	}
	for (list<Entity*>::iterator it = containedIn->entitiesContained.begin(); it != containedIn->entitiesContained.cend(); ++it)
	{
		if ((*it)->GetName() == args[3]) 
		{
			cout << "You put the " << args[1] << " in the " << args[3] << "." << endl;
			item->ChangeContainer(*it);
			return true;
		}
	}
	cout << "There's no " << args[3] << " to put the " << args[1] << " in." << endl;
	return false;
}

bool Player::Use(const vector<string>& args)
{
	Entity* item = Find(args[1], ITEM);
	if (item == nullptr) 
	{
		cout << "You're not carrying any " << args[1] << "." << endl;
		return false;
	}

	if (args.size() == 2) 
	{
		UseOneItem((Entity*)item, this);
	}
	else 
	{
		for (list<Entity*>::iterator it = containedIn->entitiesContained.begin(); it != containedIn->entitiesContained.cend(); ++it)
		{
			if ((*it)->GetName() == args[3]) 
			{
				UseTwoItems((Entity*)item, (*it), this);
				return true;
			}
		}
		cout << "There's no " << args[3] << " to use the " << args[1] << " with." << endl;
	}
	return false;
}

void Player::Tick()
{
}