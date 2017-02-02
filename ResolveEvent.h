#ifndef RESOLVEEVENT_H
#define RESOLVEEVENT_H

#include "Lib.h"
#include "UseStruct.h"
#include "NonEquipCard.h"

class ResolveEvent : public Event
{
protected:
    void execute();
public:
    UseStruct *data;
    TargetStruct *target;
    GameValue<bool> countered;
    ResolveEvent(UseStruct *d, TargetStruct *t);
    string toString(Player *p);
};

#endif // RESOLVEEVENT_H
