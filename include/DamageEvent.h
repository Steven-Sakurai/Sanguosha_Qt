#ifndef DAMAGEEVENT_H
#define DAMAGEEVENT_H
#include "Lib.h"
#include "UseStruct.h"

class DamageEvent : public Event
{
protected:
    void execute();
public:
    Player *player, *source;
    GameValue<int> value;
    Nature nature;
    vector<Card*> cards;
    UseStruct *reason;
    DamageEvent(Player* p, Player *s, int v=1, Nature nat=Normal, UseStruct *r=NULL);
    void prevent();
    void changeValue(int delta);
    string toString(Player *p);
};

#endif // DAMAGEEVENT_H
