#ifndef __Globals__
#define __Globals__

#include <iostream>
#include <string>
#include <vector>


enum Event {
	START,
	PROFESSOR_FOUND,
	GOT_MONSTER,
	BEAT_LARRY
};

extern Event CURRENT_EVENT;

extern bool GAME_OVER;

void ChangeEvent(Event &newEvent);

std::string StringToUppercase(std::string &myString);
std::vector<std::string> TokenizeString(std::string &str);
#endif