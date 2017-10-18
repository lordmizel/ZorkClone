#include <cstdlib>
#include <time.h>
#include "MonsterCreator.h"


using namespace std;

vector<string> typeOfAnimal = { 
	"duck", 
	"dog",
	"cat",
	"bear",
	"fish",
	"kangaroo",
	"crow",
	"chicken",
	"rat",
	"koala",
	"snake",
	"spider",
	"pig",
	"flower"
};

vector<string> secondPartOfName = {
	"quack",
	"hound",
	"meow",
	"ursus",
	"sushi",
	"hopper",
	"caw",
	"pluck",
	"squeak",
	"dropbear",
	"slither",
	"antula",
	"oink",
	"essia"
};

vector<string> specialPower = {
	"breathing fire.",
	"shooting laser beams through it's eyes.",
	"causing earthquakes when it walks.",
	"causing powerful electrical discharges.",
	"breathing whirlwinds.",
	"bending steel with it's headbutts.",
	"eating everything, and I mean EVERYTHING.",
	"reading your mind.",
	"spitting high-pressure water streams.",
	"appearing and disappearing at will.",
	"spitting toxic muck.",
	"screaming in obscenely high-pitched tones.",
	"making plants grow out of other bodies."
};

vector<string> firstPartOfName = {
	"Pyr",
	"Plasm",
	"Seism",
	"Elec",
	"Aer",
	"Crane",
	"Glutt",
	"Psycho",
	"Aqu",
	"Blink",
	"Venom",
	"Aud",
	"Crissant"
};

vector<string> extraFeature = {
	"long rabbit-like ears",
	"sharp and menacing teeth",
	"a head twice the size of it's torso",
	"rainbow-colored scales",
	"way too many legs",
	"eyes that stare through your soul",
	"a single twisted horn",
	"a yellow turtle-like shell",
	"spikes everywhere",
	"a distant, vacant expression",
	"two heads, for some reason,",
	"creepy human-like features"
};

vector<string> extraInfo = {
	"smell like garlic.",
	"be able to solve complicated mathematical equations.",
	"be unable to move in a straight line.",
	"sing random songs in exchange for food.",
	"have insanely high standards.",
	"steal every bucket it comes across.",
	"speak in an unnerving forgotten tongue.",
	"suffer from random seizures.",
	"like fast food above all else.",
	"appear in bad children's dreams.",
	"keep track of every victim it's killed.",
	"prefer dark, lonely places."
};

void CreateMonster(string & name, string & description, string & description2)
{
	
	//TODO: Test firstPartOfName is the same size as specialPower
	//TODO: Test secondPartOfName is the same size as typeOfAnimal

	int creaturePower = rand() % firstPartOfName.size();
	int creatureType = rand() % secondPartOfName.size();
	
	name = firstPartOfName[creaturePower] + secondPartOfName[creatureType];
	cout << name << endl;
	description = "It's a " + name + "! This " + typeOfAnimal[creatureType] + "-like monster has the power of " + specialPower[creaturePower];
	description2 = "It's got " + extraFeature[rand() % extraFeature.size()] + ", and it's also known to " + extraInfo[rand() % extraInfo.size()];
	cout << description << endl;
	cout << description2 << endl;
}
