#include "Lib.h"
#include "Dismantle.h"

bool Dismantle::legalityCheck(Player *target, PreUseStruct *d)
{
    if(target==d->player) return false;
    return target->hand.size||target->equipArea.size||target->judgeArea.size;
}

Dismantle::Dismantle() : NonEquipCard("过河拆桥",Trick)
{
}

void Dismantle::resolve(TargetStruct *target, UseStruct *d)
{
    vector<Card*> cards;
    Player *user=d->data->player,*tar=target->player;
    for(Card *c=tar->hand.next;c!=&tar->hand;c=c->next) if(user->canDiscard(c)) cards.push_back(c);
    for(Card *c=tar->equipArea.next;c!=&tar->equipArea;c=c->next) if(user->canDiscard(c)) cards.push_back(c);
    for(Card *c=tar->judgeArea.next;c!=&tar->judgeArea;c=c->next) if(user->canDiscard(c)) cards.push_back(c);
    if(cards.empty()) return;
    tar->discard(vector<Card*>(1,user->chooseCard("discard:你使用了过河拆桥",cards)));
}
