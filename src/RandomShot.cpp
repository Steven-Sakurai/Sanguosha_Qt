#include "Lib.h"
#include "RandomShot.h"
#include "Dodge.h"
#include "NeedYieldEvent.h"
#include "DamageEvent.h"

bool RandomShot::legalityCheck(Player *target, PreUseStruct *d)
{
    return target!=d->player;
}

RandomShot::RandomShot() : NonEquipCard("万箭齐发",Trick)
{
    maxTargets=game->nPlayer;
}

void RandomShot::resolve(TargetStruct *target, UseStruct *d)
{
    if(!(new NeedYieldEvent(target->player,new NameFilter<Dodge>))->happen_success())
        (new DamageEvent(target->player,d->data->player,1,Normal,d))->happen();
}

bool RandomShot::isMandatoryTarget(Player *target, PreUseStruct *d)
{
    return isLegalTarget(target,d);
}
