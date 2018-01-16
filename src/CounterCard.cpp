#include "Lib.h"
#include "CounterCard.h"
#include "ResolveEvent.h"
#include "CounterEvent.h"

bool CounterCard::legalityCheck(Player *target, PreUseStruct *d)
{
    return false;
}

bool CounterCard::canBeUsed(Timing t, Event *e, Player *p)
{
    if(t!=beforeResolve) return false;
    return canCounter(dynamic_cast<ResolveEvent*>(e),p);
}

void CounterCard::resolve(TargetStruct *target, UseStruct *d)
{
    ResolveEvent *u=dynamic_cast<ResolveEvent*>(d->data->reason);
    (new CounterEvent(u,d))->happen();
}

CounterCard::CounterCard(string name, Type t):NonEquipCard(name,t)
{
    maxTargets=0;
}
