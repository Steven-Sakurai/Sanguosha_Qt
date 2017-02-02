#include "Lib.h"
#include "Duel.h"
#include "Slash.h"
#include "NeedYieldEvent.h"
#include "DamageEvent.h"

bool Duel::legalityCheck(Player *target, PreUseStruct *d)
{
    return target!=d->player;
}

Duel::Duel() : NonEquipCard("决斗",Trick)
{
}

void Duel::resolve(TargetStruct *target, UseStruct *d)
{
    Player *user=d->data->player,*tar=target->player;\
    while(1)
    {
        if(!(new NeedYieldEvent(tar,new NameFilter<Slash>))->happen_success())
        {
            (new DamageEvent(tar,user,1,Normal,d))->happen();
            return;
        }
        if(!(new NeedYieldEvent(user,new NameFilter<Slash>))->happen_success())
        {
            (new DamageEvent(user,tar,1,Normal,d))->happen();
            return;
        }
    }
}
