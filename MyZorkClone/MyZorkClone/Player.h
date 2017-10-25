#ifndef __Player__
#define __Player__

#include <vector>
#include <string>
#include "Entity.h"
#include "Creature.h"

class Room;

class Player : public Creature {
public:
	Player(const std::string name, const std::string description, Room* room);
	~Player();

	void AssessHP() const;

	void Inventory() const;
	void Look(const std::vector<std::string>& args) const;
	bool Go(const std::vector<std::string>& args);
	bool Attack(const std::vector<std::string>& args);
	bool Talk(const std::vector<std::string>& args);
	bool Grab(const std::vector<std::string>& args);
	bool Drop(const std::vector<std::string>& args) const;
	bool Put(const std::vector<std::string>& args) const;
	bool Use(const std::vector<std::string>& args);
	
	virtual void Tick();
private:
};
#endif