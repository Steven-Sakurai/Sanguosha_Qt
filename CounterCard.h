#ifndef COUNTERCARD_H
#define COUNTERCARD_H

#include "Lib.h"
#include "NonEquipCard.h"
#include "ResolveEvent.h"

class CounterCard : public NonEquipCard
{
protected:
    virtual bool canCounter(ResolveEvent *e, Player *p)=0;
    bool legalityCheck(Player *target, PreUseStruct *d);
public:
    bool canBeUsed(Timing t, Event *e, Player *p);
    virtual void resolve(TargetStruct *target, UseStruct *d);
    CounterCard(string name,Type t);
};

#endif // COUNTERCARD_H
