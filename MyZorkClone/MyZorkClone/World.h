#ifndef __World__
#define __World__

#include <iostream>
#include <vector>
#include "Entity.h"
#include "Player.h"

class World {
public:
	World();
	~World();

	void TakeAction(std::vector<std::string> &action);

private:
	Player* player = nullptr;
	std::list<Entity*> entities;
};

#endif