#include <time.h>
#include "Battle.h"
#include "Monster.h"
#include "Player.h"
#include "Npc.h"

using namespace std;


bool IN_BATTLE = false;
Monster * YOUR_MONSTER = nullptr;
Monster* ENEMY_MONSTER = nullptr;
Player* YOU = nullptr;
Npc* RIVAL = nullptr;

BattleStance enemyStance;

void BattleStart(Monster * playerMonster, Monster * enemyMonster, Player* player, Npc* rival)
{
	YOUR_MONSTER = playerMonster;
	ENEMY_MONSTER = enemyMonster;
	YOU = player;
	RIVAL = rival;
	cout << endl << "IT'S BATTLE TIME!!" << endl;
	EnemyChangeStance();
	cout << "Please choose the type of attack you want to do: Write STRONG, FAST or SNEAKY." << endl << endl;
	IN_BATTLE = true;
}

void EnemyChangeStance()
{
	enemyStance = BattleStance(rand() % 3);
	switch ((int)enemyStance) {
	case 0:
		cout << "The enemy " << ENEMY_MONSTER->GetName() << " is popping a vein!" << endl;
		break;
	case 1:
		cout << "The enemy " << ENEMY_MONSTER->GetName() << " is skipping around!" << endl;
		break;
	case 2:
		cout << "The enemy " << ENEMY_MONSTER->GetName() << " has a weird glint in it's eyes!" << endl;
		break;
	}
	return;
}

void SolveMatch(const string & stanceChosen)
{
	if (stanceChosen == "STRONG") {
		switch ((int)enemyStance) {
		case 0:
			cout << "Both your " << YOUR_MONSTER->GetName() << " and the enemy " << ENEMY_MONSTER->GetName() << " clash with a gigantic impact!!" << endl;
			cout << "When the dust settles, both Zorkemon seem to be standing. Looks like they cancelled each other's attack!" << endl;
			break;
		case 1:
			cout << "The enemy " << ENEMY_MONSTER->GetName() << " quickly dashes at " << YOUR_MONSTER->GetName() << "!!" << endl;
			cout << "However, the fast attack only ticles the powerful muscles of your monster as it punches it's enemy with great force!!" << endl;
			ENEMY_MONSTER->Hurt();
			break;
		case 2:
			cout << "Your " << YOUR_MONSTER->GetName() << " gathers power and launches a powerful attack towards the enemy " << ENEMY_MONSTER->GetName() << "!!" << endl;
			cout << "However, the enemy monster uses your monster's own strength to flip him over to the ground!" << endl;
			YOUR_MONSTER->Hurt();
			break;
		}
	} else if (stanceChosen == "FAST"){
		switch ((int)enemyStance) {
		case 0:
			cout << "Your " << YOUR_MONSTER->GetName() << " dashes towards the enemy " << ENEMY_MONSTER->GetName() << "!!" << endl;
			cout << "But it doesn't look like it's attack has even scratched it's massive bulk! In fact it hurt itself simply by trying!" << endl;
			YOUR_MONSTER->Hurt();
			break;
		case 1:
			cout << "Both your " << YOUR_MONSTER->GetName() << " and the enemy " << ENEMY_MONSTER->GetName() << " quickly lash at each other!!" << endl;
			cout << "The battle is so fast it's hard to follow, but it doesn't look either monster has the upper hand!" << endl;
			break;
		case 2:
			cout << "Your " << YOUR_MONSTER->GetName() << " pretty much teleports next to the enemy " << ENEMY_MONSTER->GetName() << "!!" << endl;
			cout << "It manages to hit the enemy monster before it has even time to realize what just happened!" << endl;
			ENEMY_MONSTER->Hurt();
			break;
		}
	}
	else if (stanceChosen == "SNEAKY") {
		switch ((int)enemyStance) {
		case 0:
			cout << "The enemy " << ENEMY_MONSTER->GetName() << " unleashes a gigantic tackle against " << YOUR_MONSTER->GetName() << "!!" << endl;
			cout << "Your monster was expecting that! It quickly throws sand in the enemy monsters eyes in order to blind and hit him!" << endl;
			ENEMY_MONSTER->Hurt();
			break;
		case 1:
			cout << "Your " << YOUR_MONSTER->GetName() << " awaits for the enemy " << ENEMY_MONSTER->GetName() << "'s next move!!" << endl;
			cout << "However, the next attack comes so fast your monster has no time to react!" << endl;
			YOUR_MONSTER->Hurt();
			break;
		case 2:
			cout << "Your " << YOUR_MONSTER->GetName() << " decides to wait and see what the enemy " << ENEMY_MONSTER->GetName() << " does next!!" << endl;
			cout << "... Except... The enemy monster is also doing that, so both of them kinda stare at each other awkwardly..." << endl;
			break;
		}
	}

	ENEMY_MONSTER->AssessHP();
	YOUR_MONSTER->AssessHP();

	if (ENEMY_MONSTER->GetCurrentHP() <= 0) {
		cout << "YOU WIN!!" << endl;
		
	}
	else if (YOUR_MONSTER->GetCurrentHP() <= 0) {
		cout << "YOU LOSE!!" << endl;
	}
	else {
		EnemyChangeStance();
		cout << "Please choose the type of attack you want to do: Write STRONG, FAST or SNEAKY." << endl << endl;
	}
}
