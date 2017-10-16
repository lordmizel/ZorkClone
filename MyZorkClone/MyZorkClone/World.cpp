#include <iostream>
#include <vector>
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
}


World::~World(){
}


void World::TakeAction(vector<string> &actions){
	switch (actions.size()) {
	case 0:
		cout << "Please, introduce a command." << endl;
		break;
	case 1:
		// One-word commands
		if (actions[0] == "INVENTORY") {

		} else if (actions[0] == "LOOK") {

		} else if (actions[0] == "RUN" || actions[0] == "ESCAPE" || actions[0] == "FLEE") {

		} else {
			cout << "I don't understand what " << actions[0] << " means. Is it one of those new trendy words kids use today?" << endl;
		}
		break;
	case 2:
		// Two-word commands
		if (actions[0] == "LOOK" || actions[0] == "EXAMINE") {

		} else if (actions[0] == "GO") {

		} else if (actions[0] == "ATTACK") {

		} else if (actions[0] == "GRAB" || actions[0] == "GET") {

		} else if (actions[0] == "DROP" || actions[0] == "DISCARD") {

		} else {
			cout << "I don't understand what " << actions[0] << " means. Is it one of those new trendy words kids use today?" << endl;
		}
		break;
	case 3:
		cout << "What was that? I couldn't understand you, sorry." << endl;
		break;
	case 4:
		//Four-word commands
		if (actions[0] == "USE") {

		} else {
			cout << "I don't understand what " << actions[0] << " means. Is it one of those new trendy words kids use today?" << endl;
		}
		break;
	default:
		cout << "What was that? I couldn't understand you, sorry." << endl;
		break;
	}
	return;
}
