#include <sstream>
#include "Globals.h"

using namespace std;

string StringToUppercase(string & myString)
{
	int i = 0;
	char c;
	while (myString[i])
	{
		myString[i] = toupper(myString[i]);
		i++;
	}
	return myString;
}

vector<string> TokenizeString(string & str)
{
	vector<string> choppedString;
	istringstream ss(str);
	string tempString;
	while (getline(ss, tempString, ' '))
	{
		choppedString.push_back(tempString);
	}
	return choppedString;
}

