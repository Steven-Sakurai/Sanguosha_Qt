#ifndef DISMANTLE_H
#define DISMANTLE_H

#include "Lib.h"
#include "NonEquipCard.h"

class Dismantle : public NonEquipCard
{
protected:
    bool legalityCheck(Player *target, PreUseStruct *d);
public:
    Dismantle();
    void resolve(TargetStruct *target, UseStruct *d);
};

#endif // DISMANTLE_H
