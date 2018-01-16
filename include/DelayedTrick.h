#ifndef DELAYEDTRICK_H
#define DELAYEDTRICK_H

#include "Lib.h"
#include "NonEquipCard.h"

class DelayedTrick : public NonEquipCard
{
protected:
    virtual bool delayedLegalityCheck(Player *target, PreUseStruct *d)=0;
    bool legalityCheck(Player *target, PreUseStruct *d);
public:
    DelayedTrick(string name);
};

#endif // DELAYEDTRICK_H
