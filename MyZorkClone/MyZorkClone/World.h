#ifndef __World__
#define __World__

#include <iostream>
#include <vector>
#include "Entity.h"

class World {
public:
	//vector<Entity*> entities;
	//Player* player = nullptr;

	World();
	~World();
	void TakeAction(std::vector<std::string> &action);
private:
	//void CreateWorld();
	//void Update();
};

#endif