#include <iostream>
#include <string>
#include <sstream>
#include "World.h"

using namespace std;


string StringToUppercase(string myString) {
	int i = 0;
	char c;
	while (myString[i]) 
	{
		myString[i] = toupper(myString[i]);
		i++;
	}
	return myString;
}


vector<string> TokenizeString(string str) {
	vector<string> choppedString;
	istringstream ss(str);
	string tempString;
	while (getline(ss, tempString, ' ')) 
	{
		choppedString.push_back(tempString);
	}
	return choppedString;
}


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
			//TODO Enlazar con gameWorld... como sea que se suponga que tenga que hacerlo :P
		}
	}
	return 0;
}