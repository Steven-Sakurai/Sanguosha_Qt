#ifndef HPREDUCTIONEVENT_H
#define HPREDUCTIONEVENT_H
#include "Lib.h"
#include "DamageEvent.h"

class HpReductionEvent : public Event
{
protected:
    void execute();
public:
    Player *player;
    DamageEvent *damage;
    int value;
    HpReductionEvent(Player *p,int v=1,DamageEvent *d=NULL);
};

#endif // HPREDUCTIONEVENT_H
