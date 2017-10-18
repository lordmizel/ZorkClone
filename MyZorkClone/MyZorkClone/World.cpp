#include <iostream>
#include <vector>
#include <time.h>		//////////////////////////
#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "Room.h"
#include "World.h"

using namespace std;


World::World(){
	cout << "ZORKEMON: RUSTY PEBBLE EDITION" << endl;
	cout << "==============================" << endl << endl;
	cout << "Welcome to the world of Zorkemon!" << endl;
	cout << "In this world, people live alongside these mysterious beings called Zorkemon." << endl;
	cout << "That's not good, mind you... Zorkemon are dangerous as heck. I mean, we're talking mice that can " << endl 
		 << "inflict 1000V electrical discharges and such. They're nasty pieces of work, really..." << endl;
	cout << "Despite this, kids around the age of 10 receive their first Zorkemon as a present, after which they " << endl 
		 << "embark on an adventurous journey through the world. Because that sounds like a completely " << endl 
		 << "responsible thing for parents to let their kids do." << endl;
	cout << "You are one such kid. You just turned 10 and are ready to start on your magical Zorkemon journey!" << endl;
	cout << "May god have mercy on your soul." << endl << endl;

	//CREATING ENTITIES

	// -- Rooms --
	Room* bedroom = new Room("Bedroom", "This is your bedroom. It's kind of a mess, but that's to be expected since kids are creatures born from chaos.");
	Room* house = new Room("House", "You're in your living room. It's not much, but it's cozy enough.");
	Room* townSquare = new Room("Town Square", "This is the town square. A fountain decorates this otherwise unremarkable place.");
	Room* laboratory = new Room("Laboratory", "Professor Stump's laboratory. There's cool technological stuff you don't really understand laying around everywhere.");
	Room* backyard = new Room("Backyard", "Stump's backyard is not too unlike a jungle. One thing is certain, she's not too keen on gardening.");
	Room* warehouse = new Room("Warehouse", "You're in a dark and creepy warehouse. You SWEAR you saw something moving through the corner of your eye.");

	// -- Player --
	player = new Player("The kid", "You're just a normal kid who still has a spark of peppiness in your eyes.", bedroom);

	// -- Items --
	Item* key = new Item("Key", "This key is decorated with a cute squid keychain.", player);

	// -- Monster --
	srand(time(NULL));
	Monster* monster1 = new Monster("", "", bedroom);
	Monster* monster2 = new Monster("", "", bedroom);
	Monster* monster3 = new Monster("", "", bedroom);
	Monster* monster4 = new Monster("", "", bedroom);
	Monster* monster5 = new Monster("", "", bedroom);
	
}


World::~World(){
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
		delete *it;
	}

	entities.clear();
}


void World::TakeAction(vector<string> &actions){
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
		else if (actions[0] == "RUN" || actions[0] == "ESCAPE" || actions[0] == "FLEE") 
		{

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

		} 
		else if (actions[0] == "ATTACK") 
		{

		} 
		else if (actions[0] == "GRAB" || actions[0] == "GET" || actions[0] == "TAKE") 
		{

		} 
		else if (actions[0] == "DROP" || actions[0] == "DISCARD") 
		{

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
		if (actions[0] == "USE") 
		{

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
	return;
}
