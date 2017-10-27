#include <iostream>
#include <string>
#include "ItemUsage.h"
#include "Entity.h"
#include "Monster.h"
#include "Globals.h"
#include "Player.h"
#include "NpcInteractions.h"

using namespace std;


void UseOneItem(Entity * item, Player* player)
{
	string name = item->GetName();
	if (name == "BOOK") 
	{
		cout << "You start reading the book:" << endl;
		cout << "A monster can attack it's adversaries in a variety of ways. Bust there's basically three cathegories of " << endl
			 << "attacks: FAST, STRONG and SNEAKY." << endl;
		cout << "FAST attacks trade strength for velocity. They're ideal for keeping pressure, but tend to be weaker and " << endl
			 << "ineffective against monsters that are gathering their power because the sheer bulk of their muscles serves " << endl
			 << "as an armor of sorts. Still, they're great to surprise your rival before he has time to think!" << endl;
		cout << "STRONG attacks are just sheer brute force and brawn. They're intimidating and brutal, and will probably " << endl
			 << "outmatch monsters that try to take them head on. Still, intelligent monsters will probably see them coming " << endl
			 << "and be able to outmanuever them. Remember: The bigger they are, the harder they fall!" << endl;
		cout << "SNEAKY attacks make use of misdirections and feints. They're great to take our opponents who rely too much " << endl
			 << "on muscle, because they get predictable in the end. Still, they're hard to do effectively when the rival " << endl
			 << "is moving too fast, as they're harder to predict and don't leave you much time to plan your counter." << endl;
		cout << "Keeping a close eye on your rival is essential to becoming a true Zorkemon master!!" << endl;
	}
	else if (name == "MAGAZINE") 
	{
		cout << "You start reading the magazine and..." << endl << "... oh..." << endl << "... OH... OH, MY..." << endl;
		cout << "You probably shouldn't be looking at these pages..." << endl;
		cout << "You actually got hurt because of nosebleed hemorrage." << endl;
		player->Hurt();
		player->AssessHP();
	}
	else if (name == "FRUIT") 
	{
		cout << "You take a bite out of the juicy fruit." << endl;
		cout << "It turns out to be poisonous. OF COURSE IT IS. WHAT DID YOU EXPECT??" << endl;
		cout << "You're hurt because of bellyache." << endl;
		player->Hurt();
		player->AssessHP();
		item->ChangeContainer(nullptr);
	}
	else 
	{
		cout << "You can't just USE it like that..." << endl;
	}
}

void UseTwoItems(Entity * item1, Entity * item2, Player* player)
{
	string name1 = item1->GetName();
	if (name1 == "CAPSULE") 
	{
		if (item2->GetType() == MONSTER) 
		{
			Monster* monster = (Monster*)item2;
			if (monster->IsCapturable() == true) 
			{
				monster->ChangeContainer(item1);
				CURRENT_EVENT = GOT_MONSTER;
				cout << "You caught the " << monster->GetName() << "!! Your first step in order to become a true Zorkemon master!!" << endl;
			}
			else 
			{
				cout << "That monster already has an owner! You can't steal monsters who pertain to other people!" << endl;
			}
		}
		else 
		{
			cout << "The capsule is used to capture monsters. That " << item2->GetName() << " is not a monster." << endl;
		}
	}
	else if (name1 == "KEY")
	{
		cout << "Just walk through a locked door with the key in your inventory and you will open it." << endl;
	}
	else 
	{
		cout << "That doesn't seem to make much sense..." << endl;
	}
}
