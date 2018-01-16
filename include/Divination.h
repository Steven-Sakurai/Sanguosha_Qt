#ifndef DIVINATION_H
#define DIVINATION_H

#include "Lib.h"
#include "NonEquipCard.h"

class Divination : public NonEquipCard
{
protected:
    bool legalityCheck(Player *target, PreUseStruct *d);
public:
    Divination();
    void resolve(TargetStruct *target, UseStruct *d);
    bool isMandatoryTarget(Player *target, PreUseStruct *d);
};

#endif // DIVINATION_H
