#ifndef YIELDEVENT_H
#define YIELDEVENT_H

#include "Lib.h"

class YieldEvent : public Event
{
protected:
    void execute();
public:
    Player *player;
    vector<Card*> cards;
    CardInfo info;
    Event *reason;
    Transform *transform;
    bool isSpecial;
    YieldEvent(Player *p, const vector<Card*> &c, CardInfo i, Event *r, Transform *trans, bool sp=false);
    YieldEvent(Player *p, Card *c, Event *r);
    bool isLegal();
    string toString(Player *p);
};

#endif // YIELDEVENT_H
