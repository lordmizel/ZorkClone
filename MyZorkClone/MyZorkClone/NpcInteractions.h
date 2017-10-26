#ifndef __NPC_INTERACTIONS__
#define __NPC_INTERACTIONS__

#include <iostream>

class Player;

void AttackNPC(const std::string &name, Player* player);
void TalkNPC(const std::string &name, Player* player);

#endif