#ifndef __Battle__
#define __Battle__

#include <iostream>

class Monster;
class Player;
class Npc;

extern bool IN_BATTLE;

//Monster* YOUR_MONSTER;
//Monster* ENEMY_MONSTER;
//Player* YOU;
//Npc* RIVAL;

enum BattleStance {
	STRONG,
	FAST,
	SNEAKY
};

//BattleStance enemyStance;

void BattleStart(Monster* playerMonster, Monster* enemyMonster, Player* player, Npc* npc);
void EnemyChangeStance();
void SolveMatch(std::string &stanceChosen);

#endif