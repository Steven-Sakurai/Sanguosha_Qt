#include "Lib.h"
#include "Thievery.h"
#include "MoveEvent.h"

bool Thievery::legalityCheck(Player *target, PreUseStruct *d)
{
    if(target==d->player) return false;
    return target->hand.size||target->equipArea.size||target->judgeArea.size;
}

bool Thievery::distanceCheck(Player *target, PreUseStruct *d)
{
    return d->player->getDistanceTo(target)==1;
}

Thievery::Thievery() : NonEquipCard("顺手牵羊",Trick)
{
}

void Thievery::resolve(TargetStruct *target, UseStruct *d)
{
    vector<Card*> cards;
    Player *user=d->data->player,*tar=target->player;
    for(Card *c=tar->hand.next;c!=&tar->hand;c=c->next) if(user->canDiscard(c)) cards.push_back(c);
    for(Card *c=tar->equipArea.next;c!=&tar->equipArea;c=c->next) if(user->canDiscard(c)) cards.push_back(c);
    for(Card *c=tar->judgeArea.next;c!=&tar->judgeArea;c=c->next) if(user->canDiscard(c)) cards.push_back(c);
    if(cards.empty()) return;
    Card *card=user->chooseCard("acquire",cards);
    (new MoveEvent(vector<MoveStruct*>(1,new MoveStruct(card,&user->hand))))->happen();
}
