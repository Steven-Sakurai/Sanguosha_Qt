#ifndef RANDOMSHOT_H
#define RANDOMSHOT_H

#include "Lib.h"
#include "NonEquipCard.h"

class RandomShot : public NonEquipCard
{
protected:
    bool legalityCheck(Player *target, PreUseStruct *d);
public:
    RandomShot();
    void resolve(TargetStruct *target, UseStruct *d);
    bool isMandatoryTarget(Player *target, PreUseStruct *d);
};

#endif // RANDOMSHOT_H
