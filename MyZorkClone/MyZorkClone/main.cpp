#include <iostream>
#include <string>
#include <sstream>
#include "Globals.h"
#include "World.h"

using namespace std;

int main() {
	World gameWorld;

	while (1) 
	{
		string action;
		getline(cin, action);
		action = StringToUppercase(action);

		if (action == "QUIT") 
		{
			break;
		} 
		else 
		{
			vector<string> actionCommands = TokenizeString(action);
			gameWorld.TakeAction(actionCommands);
		}
	}
	return 0;
}