#ifndef __NPC_INTERACTIONS__
#define __NPC_INTERACTIONS__

#include <iostream>
#include "Npc.h"

class Player;

void AttackNPC(const std::string &name, Player* player);
void TalkNPC(const std::string &name, Player* player);
void NPCBattleResult(Player* player, Npc* rival, bool result);

#endif