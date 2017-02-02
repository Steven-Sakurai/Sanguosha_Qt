#ifndef SLASH_H
#define SLASH_H

#include "Lib.h"
#include "NonEquipCard.h"

class Slash : public NonEquipCard
{
protected:
    bool distanceCheck(Player *target, PreUseStruct *d);
    bool legalityCheck(Player *target, PreUseStruct *d);
public:
    Slash();
    virtual ~Slash();
    bool canBeUsed(Timing t, Event *e, Player *p);
    void resolve(TargetStruct *target, UseStruct *d);
};

#endif // SLASH_H
