#include <time.h>
#include "Battle.h"
#include "Monster.h"
#include "Player.h"
#include "Npc.h"
#include "NpcInteractions.h"

using namespace std;


bool IN_BATTLE = false;
Monster * yourMonster = nullptr;
Monster* enemyMonster = nullptr;
Player* you = nullptr;
Npc* rival = nullptr;

BattleStance enemyStance;

void BattleStart(Monster * playerMonster, Monster * otherMonster, Player* player, Npc* adversary)
{
	yourMonster = playerMonster;
	enemyMonster = otherMonster;
	you = player;
	rival = adversary;
	cout << endl << "IT'S BATTLE TIME!!" << endl;
	EnemyChangeStance();
	cout << "Please choose the type of attack you want to do: Write STRONG, FAST or SNEAKY." << endl << endl;
	IN_BATTLE = true;
}

void EnemyChangeStance()
{
	enemyStance = BattleStance(rand() % 3);
	switch ((int)enemyStance) 
	{
	case 0:
		cout << "The enemy " << enemyMonster->GetName() << " is popping a vein!" << endl;
		break;
	case 1:
		cout << "The enemy " << enemyMonster->GetName() << " is skipping around!" << endl;
		break;
	case 2:
		cout << "The enemy " << enemyMonster->GetName() << " has a weird glint in it's eyes!" << endl;
		break;
	}
	return;
}

void SolveMatch(const string & stanceChosen)
{
	if (stanceChosen == "STRONG") 
	{
		switch ((int)enemyStance) 
		{
		case 0:
			cout << "Both your " << yourMonster->GetName() << " and the enemy " << enemyMonster->GetName() << " clash with a gigantic impact!!" << endl;
			cout << "When the dust settles, both Zorkemon seem to be standing. Looks like they cancelled each other's attack!" << endl;
			break;
		case 1:
			cout << "The enemy " << enemyMonster->GetName() << " quickly dashes at " << yourMonster->GetName() << "!!" << endl;
			cout << "However, the fast attack only ticles the powerful muscles of your monster as it punches it's enemy with great force!!" << endl;
			enemyMonster->Hurt();
			break;
		case 2:
			cout << "Your " << yourMonster->GetName() << " gathers power and launches a powerful attack towards the enemy " << enemyMonster->GetName() << "!!" << endl;
			cout << "However, the enemy monster uses your monster's own strength to flip him over to the ground!" << endl;
			yourMonster->Hurt();
			break;
		}
	} 
	else if (stanceChosen == "FAST")
	{
		switch ((int)enemyStance) 
		{
		case 0:
			cout << "Your " << yourMonster->GetName() << " dashes towards the enemy " << enemyMonster->GetName() << "!!" << endl;
			cout << "But it doesn't look like it's attack has even scratched it's massive bulk! In fact it hurt itself simply by trying!" << endl;
			yourMonster->Hurt();
			break;
		case 1:
			cout << "Both your " << yourMonster->GetName() << " and the enemy " << enemyMonster->GetName() << " quickly lash at each other!!" << endl;
			cout << "The battle is so fast it's hard to follow, but it doesn't look either monster has the upper hand!" << endl;
			break;
		case 2:
			cout << "Your " << yourMonster->GetName() << " pretty much teleports next to the enemy " << enemyMonster->GetName() << "!!" << endl;
			cout << "It manages to hit the enemy monster before it has even time to realize what just happened!" << endl;
			enemyMonster->Hurt();
			break;
		}
	}
	else if (stanceChosen == "SNEAKY") 
	{
		switch ((int)enemyStance) 
		{
		case 0:
			cout << "The enemy " << enemyMonster->GetName() << " unleashes a gigantic tackle against " << yourMonster->GetName() << "!!" << endl;
			cout << "Your monster was expecting that! It quickly throws sand in the enemy monsters eyes in order to blind and hit him!" << endl;
			enemyMonster->Hurt();
			break;
		case 1:
			cout << "Your " << yourMonster->GetName() << " awaits for the enemy " << enemyMonster->GetName() << "'s next move!!" << endl;
			cout << "However, the next attack comes so fast your monster has no time to react!" << endl;
			yourMonster->Hurt();
			break;
		case 2:
			cout << "Your " << yourMonster->GetName() << " decides to wait and see what the enemy " << enemyMonster->GetName() << " does next!!" << endl;
			cout << "... Except... The enemy monster is also doing that, so both of them kinda stare at each other awkwardly..." << endl;
			break;
		}
	}

	enemyMonster->AssessHP();
	yourMonster->AssessHP();

	if (enemyMonster->GetCurrentHP() <= 0)
	{
		NPCBattleResult(you, rival, true);
		IN_BATTLE = false;
	}
	else if (yourMonster->GetCurrentHP() <= 0)
	{
		NPCBattleResult(you, rival, false);
		IN_BATTLE = false;
	}
	else 
	{
		EnemyChangeStance();
		cout << "Please choose the type of attack you want to do: Write STRONG, FAST or SNEAKY." << endl << endl;
	}
}
