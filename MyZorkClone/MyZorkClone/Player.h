#ifndef __Player__
#define __Player__

#include <vector>
#include <string>
#include "Entity.h"
#include "Creature.h"

class Room;

const int MAX_PLAYER_HP = 3;

class Player : public Creature {
public:
	Player(const std::string name, const std::string description, Room* room);
	~Player();

	void Inventory() const;
	void Look(const std::vector<std::string>& args) const;
	void Escape(const std::vector<std::string>& args);

	bool Go(const std::vector<std::string>& args);
	bool Attack(const std::vector<std::string>& args);
	bool Grab(const std::vector<std::string>& args);
	bool Drop(const std::vector<std::string>& args);

	bool Use(const std::vector<std::string>& args);
	
	virtual void Tick();
	virtual void Die();
private:
	int hp = MAX_PLAYER_HP;
};
#endif