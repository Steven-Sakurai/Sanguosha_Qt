#ifndef DUEL_H
#define DUEL_H

#include "Lib.h"
#include "NonEquipCard.h"

class Duel : public NonEquipCard
{
protected:
    bool legalityCheck(Player *target, PreUseStruct *d);
public:
    Duel();
    void resolve(TargetStruct *target, UseStruct *d);
};

#endif // DUEL_H
