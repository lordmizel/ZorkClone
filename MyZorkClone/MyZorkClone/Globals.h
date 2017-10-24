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

static Event CURRENT_EVENT = START;

static bool GAME_OVER = false;

std::string StringToUppercase(std::string &myString);
std::vector<std::string> TokenizeString(std::string &str);
#endif