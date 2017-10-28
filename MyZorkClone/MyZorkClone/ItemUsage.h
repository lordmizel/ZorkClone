#ifndef __ItemUsage__
#define __ItemUsage__


class Entity;
class Player;

void UseOneItem(Entity* item, Player* player);
void UseTwoItems(Entity* item1, Entity* item2, Player* player);

#endif