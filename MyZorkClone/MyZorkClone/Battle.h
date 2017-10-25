#ifndef __Battle__
#define __Battle__

#include <iostream>

class Monster;
class Player;
class Npc;

extern bool IN_BATTLE;

enum BattleStance {
	STRONG,
	FAST,
	SNEAKY
};

void BattleStart(Monster * playerMonster, Monster* enemyMonster, Player* player, Npc* npc);
void EnemyChangeStance();
void SolveMatch(const std::string &stanceChosen);

#endif