#ifndef THIEVERY_H
#define THIEVERY_H

#include "Lib.h"
#include "NonEquipCard.h"

class Thievery : public NonEquipCard
{
protected:
    bool legalityCheck(Player *target, PreUseStruct *d);
    bool distanceCheck(Player *target, PreUseStruct *d);
public:
    Thievery();
    void resolve(TargetStruct *target, UseStruct *d);
};

#endif // THIEVERY_H
