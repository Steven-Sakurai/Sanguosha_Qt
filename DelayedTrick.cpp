#include "Lib.h"
#include "DelayedTrick.h"

bool DelayedTrick::legalityCheck(Player *target, PreUseStruct *d)
{
    if(d->player==NULL||delayedLegalityCheck(target,d))
    {
        for(Card *c=target->judgeArea.next;c!=&target->judgeArea;c=c->next)
            if(c->getCardInfo().name==this&&c!=d->cards[0]) return false;
        return true;
    }
    return false;
}

DelayedTrick::DelayedTrick(string name) : NonEquipCard(name,Trick)
{
    isDelayedTrick=true;
}
