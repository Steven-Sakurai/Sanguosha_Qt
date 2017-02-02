#ifndef DYINGEVENT_H
#define DYINGEVENT_H

#include "Lib.h"
#include "DamageEvent.h"

class DyingEvent : public Event
{
protected:
    void execute();
public:
    Player *player;
    DamageEvent *damage;
    DyingEvent(Player *p, DamageEvent *d);
    string toString(Player *p);
};

#endif // DYINGEVENT_H
