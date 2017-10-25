#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include "Globals.h"
#include "World.h"

using namespace std;


int main() {
	World gameWorld;
	char key;
	string action;

	while (1) 
	{
		if (_kbhit() != 0)
		{
			key = _getch();
			if (key == '\b') { // backspace
				if (action.length() > 0)
				{
					action.pop_back();
					cout << '\b';
					cout << " ";
					cout << '\b';
				}
			}
			else if (key != '\r') // return
			{
				action += key;
				cout << key;
			}
			else {
				if (action == "QUIT")
				{
					break;
				}
				else
				{
					cout << endl;
					vector<string> actionCommands = TokenizeString(StringToUppercase(action));
					gameWorld.TakeAction(actionCommands);
					action = "";
				}
			}
		}
	}
	return 0;
}