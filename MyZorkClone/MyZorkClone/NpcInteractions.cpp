#include <iostream>
#include <string>
#include "NpcInteractions.h"
#include "Player.h"
#include "Item.h"
#include "Globals.h"
#include "Battle.h"

using namespace std;


bool checkGiven = false;
bool capsuleGiven = false;

void AttackNPC(string name, Player* player)
{
	if (name == "MOTHER") {
		cout << "Just before you can act, your mother sends one of her trademarked icy stares at you." << endl;
		cout << "-And what, pray tell, are you plotting exactly?- she asks in what seems like a mix " << endl
			 << "between a growl and a whisper." << endl;
		cout << "You KNOW she's onto you. Your survival incstinct is telling you to avoid any " << endl
			 << "aggressive course of action towards your mother, or else you could actually DIE." << endl;
	}
	else if (name == "LARRY") {
		cout << "Larry simply laughs at you and throws a pack of bills at your face. The impact throws you " << endl
			 << "off-track and makes you fall over." << endl;
		cout << "-Serves you right! I have far too much money for you to ever dream of hitting me anyway!" << endl;
	}
	else if (name == "PROFESSOR") {
		cout << "Right as you try to punch Stump, you feel an electrical discharge rock through your " << endl
			 << "body." << endl;
		cout << "-My, oh, my!- The Professor exclaims. -Typical of your kind to try and resort to " << endl
			 << "violence! You're probably asking yourself what would happen if you attacked poor " << endl
			 << "little old me, but unfortunately for you I foresaw this in advance!" << endl;
		cout << "That's when you notice the Professor has a force field protecting her body. This " << endl
			 << "feels strangely unfair, for some reason." << endl;
		player->Hurt();
		player->AssessHP();
	}
}

void TalkNPC(string name, Player * player)
{
	if (name == "MOTHER") {
		if (player->GetCurrentHP() < player->GetMaxHP()) {
			cout << "Your mother raises an eyebrow when she sees you. -Geez, how do you always manage to get yourself into " << endl
				 << "so much trouble?- She then offers you a piece of cake." << endl;
			cout << "As you eat, you feel your wounds healing themselves." << endl;
			cout << "-Yeah, I still don't understand how you do that. Healing just by eating cake, I mean. You're a weird " << endl
				 << "one." << endl;
			int newPlayerHP = player->GetMaxHP();
			player->SetCurrentHP(newPlayerHP);
			/*player->currentHP = player->maxHP;*/
			player->AssessHP();
		} 
		else
		{
			switch (CURRENT_EVENT) {
			case START:
				cout << "-So the day has finally come, hasn't it?- She says as she grabs some chips from the bag. -When I " << endl
					 << "was your age I too went on a journey to become a Zorkemon master... whatever that means. However, " << endl
					 << "it is illegal for adults to compete in the big leagues." << endl;
				cout << "She changes the channel to some kind of crappy reality show about tunning toasters." << endl;
				cout << "-Whatever you do, remember you're always welcome back home. Just... try to keep away for a while, ok? " << endl
					 << "Not that I don't want to have you around, mind you, it's just... Whatever, just go." << endl;
				cout << "She points to the door. This is your cue to exit." << endl;
				break;
			case PROFESSOR_FOUND:
				cout << "-Oh, so you met Stump? Did you know we were both best pals in high-school? She was actually really " << endl
					 << "fun to have around. I mean, I would have died of boredom without her to bully or play pranks to. " << endl 
					 << "She's got this weird obsession with squids. I don't get it...- She shrugs.";
				cout << "-Someone locked her in her own warehouse, you say? My, my... I wonder who could do such a childish " << endl
					 << "thing...- She says as she opens a can of beer, and you notice her eyes fidget a bit. -Yeah... " << endl
					 << "I wonder..." << endl;
				break;
			case GOT_MONSTER:
				cout << "You try to start a conversation with your mother, but she seems way too invested in her TV drama." << endl;
				cout << "She might just be ignoring you on purpose." << endl;
				break;
			case BEAT_LARRY:
				cout << "-I heard you beat that rich kid next door. I am so proud of you. I'd treat you to a beer, but you're " << endl
					 << "way too young to drink alcohol, aren't you? So instead I'll drink it for you! Cheers!- She happily " << endl
					 << "beams as she opens two more beer cans. It's amazing how she can drink so much and yet only end up " << endl
					 << "with minor tipsiness." << endl;
				break;
			}
		}
	}
	else if (name == "LARRY") 
	{
		switch (CURRENT_EVENT) {
		case START:
			if (!checkGiven) {
				cout << "Larry diverges his attention from his legion of fangirls and smirks as he sees you come closer." << endl;
				cout << "-Oh, hello, did you come to see if I had some spare change to give? Here, let me help your " << endl
					 << "moneyless self to get a bit further away from your misery." << endl;
				cout << "He extends you a blank check worth a hundred dollars." << endl;
				cout << "-Allow me to help. You need to go to the bank in order to retrieve the money. Yeah, the bank, " << endl
					 << "you know, that place where people with money bring the money to keep it safe. I'm sure you've " << endl
					 << "heard of it, though I suppose plebs like you are not too accustomed to visit it." << endl;
				Item* check = new Item("CHECK", "This check is worth 100 dollars. Make sure to exchange it next time you go to the bank.", player);
				checkGiven = true;
			}
			else 
			{
				cout << "-Ah, you poor, poor penniless bloke... I forgot there's no bank in this village, so you'd need " << endl
					 << "to travel to the city in order to exchange that check. But there's no way you can afford enough " << endl
					 << "gasoline to get there. I could give you a ride on my unnecessarily large limousine, but I'm " << endl
					 << "supposed to wait here for the helicopter carrying the giant golden statue of myself it's going to " << endl
					 << "be installed in this very square this afternoon." << endl;
			}
			break;
		case PROFESSOR_FOUND:
			cout << "Larry sits with a self-sufficient grin as one of his servants massages his back. -Someone locked the " << endl
				 << "professor inside the warehouse? Peasants really do play the silliest games. - He chuckles. -You're " << endl
				 << "not accusing me, are you? The professor is kinda amusing, even by commoner standards. What's the point " << endl
				 << "of an entertainer if you're going to keep her locked up?" << endl;
			break;
		case GOT_MONSTER: {
			cout << "-You have a monster? You?- He looks actually surprised. -I must admit I didn't expect for a low-born " << endl
				<< "such as yourself to actually have one. I do train monsters as well, see? Naturally, my list of " << endl
				<< "achievements is just as large as the number of digits in my bank account. Allow me to show you..." << endl;
			Entity* larrysMonster = player->ContainedIn()->Find(MONSTER);
			Entity* yourMonster = player->Find("CAPSULE", ITEM)->Find(MONSTER);
			Entity* larry = player->ContainedIn()->Find("LARRY", NPC);
			BattleStart((Monster*)yourMonster, (Monster*)larrysMonster, player, (Npc*)larry);
			break;
		}
		case BEAT_LARRY:
			cout << "He throws his arms up dramatically. -Haven't you humiliated me enough? Alas, poor you, you might have " << endl
				<< "defeated me in a monster battle, but that means nothing. The only reality is that I'm still obscenely " << endl
				<< "rich." << endl;
			break;
		}
	}
	else if (name == "PROFESSOR")
	{
		switch (CURRENT_EVENT) {
		case START: {
			cout << "The professor greets you when you come close. -Oh! F-finally! I thought I was gonna die in here. Someone locked " << endl
				 << "me inside when I was busy looking for some pieces to tinker around..." << endl;
			cout << "She adjusts her glasses and looks around. -I know! Come and see me at the lab. I might have something to give " << endl
				 << "you for your troubles!- She stumbles and almost trips on her way to the exit." << endl;
			Entity* prof = player->ContainedIn()->Find("PROFESSOR", NPC);
			Exit* toTown = (Exit*)prof->ContainedIn()->Find("DOOR", EXIT);
			Room* town = toTown->destination;
			Exit* toLab = (Exit*)town->Find("LABORATORY", EXIT);
			Room* lab = toLab->destination;
			prof->ChangeContainer(lab);
			CURRENT_EVENT = PROFESSOR_FOUND;
			break;
		}
		case PROFESSOR_FOUND: 
			if (!capsuleGiven) {
				cout << "-Ah! There you are! Here, let me give you this as thanks.- She gives a small spherical capsule to you. -It's a " << endl
					 << "monster capsule, created by none other than me! I don't have an IQ of over 200 for nothing!- She laughs." << endl;
				cout << "-Just use it on a monster and you will capture it! Since it's a special capsule made by me, there's no way the " << endl
					 << "monster will escape. Just like the squid doesn't let go of their prey. I'm hungry now.- Just like that, she goes" << endl
					 << "back yo her work." << endl;
				Item* capsule = new Item("CAPSULE", "This is an experimental capsule designed to capture monsters.", player);
				capsuleGiven = true;
			}
			else {
				cout << "The professor is eating a fried squid ring sandwich." << endl;
				cout << "-Rememfer: ufe dee capfule on a monftah do capfure eet.- She says with her mouth full. Looks like she's busy." << endl;
			}
			break;
		case GOT_MONSTER:
			cout << "-D-did you capture a monster already? Wait, the capsule actually worked!? I mean... Of course it worked! Man, I really " << endl
				 << "am a genius!- She laughs loudly again." << endl;
			cout << "-Anyway, you could try your luck battling now. I'm sure someone around the village has a monster of his own." << endl;
			break;
		case BEAT_LARRY:
			cout << "-I heard you had your first victory already. Must be exilarating for someone so full of youth and energy. I was never " << endl
				 << "too fond of the whole battling thing, however. Competition is not my thing. But SCIENCE... Man, science really gets me " << endl
				 << "all randy!" << endl;
			break;
		}
	}
}
