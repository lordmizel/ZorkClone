#ifndef __Room__
#define __Room__

#include "Entity.h"


class Exit;

class Room : public Entity {
public:

	Room(const std::string &name, const std::string &description);
	~Room();

	void Look() const;
	Exit* GetExit(const std::string &name);

};

#endif