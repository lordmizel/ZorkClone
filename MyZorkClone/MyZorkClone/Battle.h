#ifndef __Battle__
#define __Battle__

#include <iostream>
#include <vector>
#include "Entity.h"

static bool IN_BATTLE = false;
static Entity* YOUR_MONSTER = nullptr;
static Entity* ENEMY_MONSTER = nullptr;

std::vector<std::string> battleStance;
std::string enemyStance;

std::string EnemyChangeStance();
void SolveMatch(std::string &stanceChosen);

#endif