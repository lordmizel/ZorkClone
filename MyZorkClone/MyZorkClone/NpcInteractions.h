#ifndef __NPC_INTERACTIONS__
#define __NPC_INTERACTIONS__

#include <iostream>

class Player;

void AttackNPC(std::string name, Player* player);
void TalkNPC(std::string name, Player* player);


#endif