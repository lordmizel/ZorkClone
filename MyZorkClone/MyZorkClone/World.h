#ifndef __World__
#define __World__

#include <iostream>
#include <vector>
#include <time.h>
#include <list>

#define TICK_FREQUENCY 0.5f


class Entity;
class Player;

class World {
public:
	World();
	~World();

	void Tick(std::vector<std::string>& args);
	void GameLoop();
	void TakeAction(std::vector<std::string> &action);

private:
	clock_t timer;
	Player* player = nullptr;
	std::list<Entity*> entities;
};

#endif