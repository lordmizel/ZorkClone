#include <iostream>
#include <string>
#include <sstream>
#include "World.h"

using namespace std;


string StringToUppercase(string myString) {
	int i = 0;
	char c;
	while (myString[i]) {
		myString[i] = toupper(myString[i]);
		i++;
	}
	return myString;
}


vector<string> TokenizeString(string str) {
	vector<string> choppedString;
	istringstream ss(str);
	string tempString;
	while (getline(ss, tempString, ' ')) {
		choppedString.push_back(tempString);
	}
	return choppedString;
}


int main() {
	World gameWorld;

	



	while (1) {
		string action;
		getline(cin, action);
		action = StringToUppercase(action);

		if (action == "QUIT") {
			break;
		} else {
			vector<string> actionCommands = TokenizeString(action);
			
			for (vector<string>::iterator it = actionCommands.begin(); it != actionCommands.end(); it++) {
				cout << *it << endl;
			}

			gameWorld.TakeAction(actionCommands);
			//TODO Enlazar con gameWorld... como sea que se suponga que tenga que hacerlo :P
		}
		cout << "Fin del bucle" << endl;

	}
	return 0;
}