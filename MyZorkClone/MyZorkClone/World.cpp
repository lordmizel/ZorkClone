#include "Entity.h"
#include "Player.h"
#include "Globals.h"
#include "Exit.h"
#include "Item.h"
#include "Npc.h"
#include "Monster.h"
#include "Room.h"
#include "World.h"
#include "Battle.h"

using namespace std;


World::World()
{
	srand((unsigned int)time(NULL));
	timer = clock();

	cout << "ZORKEMON: RUSTY PEBBLE VERSION" << endl;
	cout << "==============================" << endl << endl;
	cout << "Welcome to the world of Zorkemon!" << endl;
	cout << "In this world, people live alongside these mysterious beings called Zorkemon." << endl;
	cout << "That's not good, mind you... Zorkemon are dangerous as heck. I mean, we're talking mice that can " << endl 
		 << "inflict 1000V electrical discharges and such. They're nasty pieces of work, really..." << endl;
	cout << "Despite this, kids around the age of 10 receive their first Zorkemon as a present, after which they " << endl 
		 << "embark on an adventurous journey through the world. Because that sounds like a completely " << endl 
		 << "responsible thing for parents to let their kids do." << endl;
	cout << "You are one such kid. You just turned 10 and are ready to start on your magical Zorkemon journey!" << endl;
	cout << "Your resolve for the day: Beat your first rival trainer in battle!" << endl;
	cout << "May god have mercy on your soul." << endl << endl;

	//CREATING ENTITIES

	// -- Rooms --
	Room* bedroom = new Room("BEDROOM", "This is your bedroom. It's kind of a mess, but that's to be expected since kids are creatures born from chaos.");
	Room* house = new Room("HOUSE", "You're in your living room. It's not much, but it's cozy enough.");
	Room* townSquare = new Room("TOWN", "This is the town square. A fountain decorates this otherwise unremarkable place.");
	Room* laboratory = new Room("LABORATORY", "Professor Stump's laboratory. There's cool technological stuff you don't really understand laying around everywhere.");
	Room* backyard = new Room("BACKYARD", "Stump's backyard is not too unlike a jungle. One thing is certain: she's not too keen on gardening.");
	Room* warehouse = new Room("WAREHOUSE", "You're in a dark and creepy warehouse. You could hide a body in here and nobody would notice. Just saying...");
	entities.push_back(bedroom);
	entities.push_back(house);
	entities.push_back(townSquare);
	entities.push_back(laboratory);
	entities.push_back(backyard);
	entities.push_back(warehouse);

	// -- Npcs --
	Npc* mother = new Npc("MOTHER", "Your mother is watching TV on the sofa while muching a bunch of chips.", house);
	Npc* larry = new Npc("LARRY", "It's Larry. Everybody knows Larry. He's kind of obnoxious, and also ridiculously rich.", townSquare);
	Npc* professor = new Npc("PROFESSOR", "Professor Stump is a ditzy-looking young woman wearing a labcoat way over her size and eternally unkept hair.", warehouse);
	entities.push_back(mother);
	entities.push_back(larry);
	entities.push_back(professor);

	// -- Player --
	player = new Player("THE KID", "You're just a normal kid who still has a spark of peppiness in your eyes.", bedroom);
	entities.push_back(player);

	// -- Items --
	Item* key = new Item("KEY", "This key is decorated with a cute squid keychain.", backyard);
	Item* bookCase = new Item("BOOKCASE", "This is just your typical run of the mill bookcase.", bedroom, true, false);
	Item* bed = new Item("BED", "Your bed. It's undone, as per usual. The sheets have dragon drawings.", bedroom, false, false);
	Item* book = new Item("BOOK", "It is called 'Tips and Tricks for the Rookie Monster Trainer'.", bookCase);
	Item* tv = new Item("TV", "The TV is on, but you fear watching it for too long might have a negative impact on your neurones.", house, false, false);
	Item* machine = new Item("MACHINE", "It's a weird fantastical multi-colored machine from the future!", laboratory, false, false);
	Item* aquarium = new Item("AQUARIUM", "There's a bunch of cephalopods swimming around in there.", laboratory, true, false);
	Item* fruit = new Item("FRUIT", "It's a red, delicious-looking fruit. Looks juicy.", backyard);
	Item* box = new Item("BOX", "This wooden crate is marked as Professor Stump's property, and is open.", warehouse, true, false);
	Item* magazine = new Item("MAGAZINE", "There's a woman dressed as a bunny in the cover. Some Halloween costume catalog, probably.", box);
	Item* capsule = new Item("CAPSULE", "This is an experimental capsule designed to capture monsters.", professor);
	Item* check = new Item("CHECK", "This check is worth 100 dollars. Make sure to exchange it next time you go to the bank.", larry);
	entities.push_back(key);
	entities.push_back(bookCase);
	entities.push_back(bed);
	entities.push_back(book);
	entities.push_back(tv);
	entities.push_back(machine);
	entities.push_back(aquarium);
	entities.push_back(fruit);
	entities.push_back(box);
	entities.push_back(magazine);
	entities.push_back(capsule);
	entities.push_back(check);

	// -- Monster --
	Monster* capturableMonster = new Monster("", "", backyard, true);
	Monster* larryMonster = new Monster("", "", townSquare, false);
	entities.push_back(capturableMonster);
	entities.push_back(larryMonster);

	// -- Exits --
	Exit* bedroomToHouse = new Exit("STAIRS", "DOWN", "There's a set of stairs going down to the first floor.", bedroom, house);
	Exit* houseToBedroom = new Exit("STAIRS", "UP", "There's a set of stairs going up to your bedroom.", house, bedroom);
	Exit* houseToSquare = new Exit("DOOR", "TOWN", "You can exit your house through the front door from here.", house, townSquare);
	Exit* squareToHouse = new Exit("HOUSE", "HOUSE", "Your house is right there, and the door is usually open.", townSquare, house);
	Exit* squareToLab = new Exit("LABORATORY", "LAB", "Professor Stump's laboratory is near. She's got an open doors policy.", townSquare, laboratory);
	Exit* labToSquare = new Exit("DOOR", "TOWN", "The door behind you goes straight back to town.", laboratory, townSquare);
	Exit* squareToBackyard = new Exit("PATH", "BACKYARD", "A messy path of thistles and nettles goes to Professor Stump's backyard.", townSquare, backyard);
	Exit* backyardToSquare = new Exit("PATH", "TOWN", "The grassy path behind you would probably take you back to civilization.", backyard, townSquare);
	Exit* squareToWarehouse = new Exit("WAREHOUSE", "WAREHOUSE", "There's an old warehouse nearby, with a shaky-looking door.", townSquare, warehouse, true, key);
	Exit* warehouseToSquare = new Exit("DOOR", "TOWN", "You can always take the door back to the town square.", warehouse, townSquare);
	entities.push_back(bedroomToHouse);
	entities.push_back(houseToBedroom);
	entities.push_back(houseToSquare);
	entities.push_back(squareToHouse);
	entities.push_back(squareToLab);
	entities.push_back(labToSquare);
	entities.push_back(squareToBackyard);
	entities.push_back(backyardToSquare);
	entities.push_back(squareToWarehouse);
	entities.push_back(warehouseToSquare);

	player->ContainedIn()->Look();
	cout << endl;
}

World::~World()
{
	for (list<Entity*>::reverse_iterator it = entities.rbegin(); it != entities.rend(); ++it) 
	{
		if (*it != nullptr) 
		{
			delete *it;
			*it = nullptr;
		}
	}
	entities.clear();
}

void World::Tick(vector<string>& args)
{
	if (args.size() > 0 && args[0].length() > 0) 
	{
		TakeAction(args);
	}
	GameLoop();
}

void World::GameLoop()
{
	clock_t now = clock();

	if ((now - timer) / CLOCKS_PER_SEC > TICK_FREQUENCY)
	{
		for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) 
		{
			(*it)->Tick();
		}
		timer = now;
	}
}

void World::TakeAction(vector<string> &actions)
{
	if (!GAME_OVER) 
	{
		if (!IN_BATTLE) 
		{
			//Normal game commands
			switch (actions.size())
			{
			case 0:
				cout << "Please, introduce a command." << endl;
				break;
			case 1:
				// One-word commands
				if (actions[0] == "INVENTORY")
				{
					player->Inventory();
				}
				else if (actions[0] == "LOOK")
				{
					player->Look(actions);
				}
				else
				{
					cout << "I don't understand what " << actions[0] << " means. Is it one of those new trendy words kids use today?" << endl;
				}
				break;
			case 2:
				// Two-word commands
				if (actions[0] == "LOOK" || actions[0] == "EXAMINE")
				{
					player->Look(actions);
				}
				else if (actions[0] == "GO")
				{
					player->Go(actions);
				}
				else if (actions[0] == "ATTACK")
				{
					player->Attack(actions);
				}
				else if (actions[0] == "TALK" || actions[0] == "SPEAK")
				{
					player->Talk(actions);
				}
				else if (actions[0] == "GRAB" || actions[0] == "GET" || actions[0] == "TAKE")
				{
					player->Grab(actions);
				}
				else if (actions[0] == "DROP" || actions[0] == "DISCARD")
				{
					player->Drop(actions);
				}
				else if (actions[0] == "USE")
				{
					player->Use(actions);
				}
				else
				{
					cout << "I don't understand what " << actions[0] << " means. Is it one of those new trendy words kids use today?" << endl;
				}
				break;
			case 3:
				cout << "That makes no sense..." << endl;
				break;
			case 4:
				//Four-word commands
				if (actions[0] == "GRAB" || actions[0] == "GET" || actions[0] == "TAKE")
				{
					player->Grab(actions);
				}
				else if (actions[0] == "PUT" || actions[0] == "PLACE")
				{
					player->Put(actions);
				}
				else if (actions[0] == "USE")
				{
					player->Use(actions);
				}
				else
				{
					cout << "I don't understand what " << actions[0] << " means. Is it one of those new trendy words kids use today?" << endl;
				}
				break;
			default:
				cout << "What was that? I couldn't understand you, sorry." << endl;
				break;
			}
			cout << endl;
		}
		else {
			//Battle commands
			switch (actions.size())
			{
			case 0:
				cout << "Please, introduce the type of attack you want your monster to do." << endl;
				break;
			case 1:
				if (actions[0] == "STRONG" || actions[0] == "FAST" || actions[0] == "SNEAKY")
				{
					SolveMatch(actions[0]);
				}
				else {
					cout << "That's not a type of attack. Attacks can be STRONG, FAST or SNEAKY." << endl;
				}
				break;
			default:
				cout << "Just write the type of attack you want to do: STRONG, FAST or SNEAKY." << endl;
			}
		}
	}
	else 
	{
		cout << "You can't do anything when you're dead. This is not a zombie game." << endl << "Type QUIT to end the game." << endl << endl;
	}
	return;
}
