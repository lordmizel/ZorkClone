#ifndef __Room__
#define __Room__

#include "Entity.h"
#include "Exit.h"

class Room : public Entity {
public:

	Room(const std::string &name, const std::string &description);
	~Room();

	void Look() const;
	Exit* GetExit(const std::string &name);

};

#endif