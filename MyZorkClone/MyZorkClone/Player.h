#ifndef __Player__
#define __Player__


#include "Entity.h"
#include "Creature.h"

class Room;

class Player : public Creature {
public:
	Player(const std::string name, const std::string description, Room* room);
	~Player();

	virtual void Inventory() const;
	/*virtual void Look(const std::vector<string>& args) const;
	virtual void Escape(const std::vector<string>& args);

	virtual bool Go(const std::vector<string>& args);
	virtual bool Attack(const std::vector<string>& args);
	virtual bool Grab(const std::vector<string>& args);
	virtual bool Drop(const std::vector<string>& args);

	virtual bool Use(const std::vector<string>& args);*/
	
	virtual void Tick();
	virtual void Die();
private:

};
#endif