#ifndef __Exit__
#define __Exit__

#include <string>

#include "Entity.h"

class Room;

class Exit : public Entity {
public:
	Exit(const std::string name, const std::string alternateName, std::string description, Room* room, Room* destination);
	Exit(const std::string name, const std::string alternateName, std::string description, Room* room, Room* destination, bool locked);
	~Exit();

	Room* destination;
	std::string alternateName;
	bool locked = false;
private:

};
#endif