#ifndef __Exit__
#define __Exit__


#include "Entity.h"

class Room;
class Item;

class Exit : public Entity {
public:
	Exit(const std::string &name, const std::string &alternateName, const std::string &description, Room* room, Room* destination);
	Exit(const std::string &name, const std::string &alternateName, const std::string &description, Room* room, Room* destination, bool locked, Item* key);
	~Exit();

	void LockState(bool lock);

	Room* GetDestination() const;
	std::string GetAlternateName() const;
	bool IsLocked() const;
	Item* GetAssociatedKey() const;

private:
	Room* destination;
	std::string alternateName;
	bool locked = false;
	Item* key;
};
#endif