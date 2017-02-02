#include "Lib.h"
#include "SouthernIntruder.h"
#include "Slash.h"
#include "NeedYieldEvent.h"
#include "DamageEvent.h"

bool SouthernIntruder::legalityCheck(Player *target, PreUseStruct *d)
{
    return target!=d->player;
}

SouthernIntruder::SouthernIntruder() : NonEquipCard("南蛮入侵",Trick)
{
    maxTargets=game->nPlayer;
}

void SouthernIntruder::resolve(TargetStruct *target, UseStruct *d)
{
    if(!(new NeedYieldEvent(target->player,new NameFilter<Slash>))->happen_success())
        (new DamageEvent(target->player,d->data->player,1,Normal,d))->happen();
}

bool SouthernIntruder::isMandatoryTarget(Player *target, PreUseStruct *d)
{
    return isLegalTarget(target,d);
}
