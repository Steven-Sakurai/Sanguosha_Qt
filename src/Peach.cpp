#include "Lib.h"
#include "Peach.h"
#include "EventBegin.h"
#include "UseEvent.h"
#include "RecoverEvent.h"
#include "DyingEvent.h"

bool Peach::legalityCheck(Player *target, PreUseStruct *d)
{
    if(d->timing==duringDying)
    {
        DyingEvent *dying=dynamic_cast<DyingEvent*>(d->reason);
        return target==dying->player;
    }
    return target->getLostHp();
}

Peach::Peach() : NonEquipCard("桃",Basic)
{
}

bool Peach::canBeUsed(Timing t, Event *e, Player *p)
{
    if(!NonEquipCard::canBeUsed(t,e,p)) return t==duringDying;
    return true;
}

void Peach::resolve(TargetStruct *target, UseStruct *d)
{
    (new RecoverEvent(target->player))->happen();
}

bool Peach::isMandatoryTarget(Player *target, PreUseStruct *d)
{
    if(d->timing==duringDying) return legalityCheck(target,d);
    return target==d->player;
}
