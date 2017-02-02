#ifndef PEACH_H
#define PEACH_H

#include "Lib.h"
#include "NonEquipCard.h"

class Peach : public NonEquipCard
{
protected:
    bool legalityCheck(Player *target, PreUseStruct *d);
public:
    Peach();
    bool canBeUsed(Timing t, Event *e, Player *p);
    void resolve(TargetStruct *target, UseStruct *d);
    bool isMandatoryTarget(Player *target, PreUseStruct *d);
};

#endif // PEACH_H
