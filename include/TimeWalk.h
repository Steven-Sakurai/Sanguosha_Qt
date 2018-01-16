#ifndef TIMEWALK_H
#define TIMEWALK_H

#include "Lib.h"
#include "DelayedTrick.h"

class TimeWalk : public DelayedTrick
{
protected:
    bool delayedLegalityCheck(Player *target, PreUseStruct *d);
public:
    TimeWalk();
    void resolve(TargetStruct *target, UseStruct *d);
};

#endif // TIMEWALK_H
