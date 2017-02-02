#ifndef DEATHEVENT_H
#define DEATHEVENT_H

#include "Lib.h"
#include "DamageEvent.h"

class DeathEvent : public Event
{
protected:
    void execute();
public:
    Player *player;
    DamageEvent *damage;
    DeathEvent(Player *p, DamageEvent *d);
    Player* getKiller();
    string toString(Player *p);
};

#endif // DEATHEVENT_H
