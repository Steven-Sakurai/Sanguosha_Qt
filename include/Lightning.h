#ifndef LIGHTNING_H
#define LIGHTNING_H

#include "Lib.h"
#include "DelayedTrick.h"

class Lightning : public DelayedTrick
{
protected:
    bool delayedLegalityCheck(Player *target, PreUseStruct *d);
public:
    Lightning();
    void resolve(TargetStruct *target, UseStruct *d);
};

#endif // LIGHTNING_H
