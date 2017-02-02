#ifndef NONEQUIPCARD_H
#define NONEQUIPCARD_H

#include "CardType.h"
#include "UseStruct.h"

class NonEquipCard : public CardType
{
public:
    NonEquipCard(string name,Type t);
    virtual bool use(PreUseStruct *d);
    virtual void resolve(TargetStruct *target,UseStruct *d)=0;
    virtual bool extraChoice(UseStruct *d);
};

#endif // NONEQUIPCARD_H
