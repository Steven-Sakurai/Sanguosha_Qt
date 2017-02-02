#ifndef NEEDYIELDEVENT_H
#define NEEDYIELDEVENT_H

#include "Lib.h"
#include "CardFilter.h"

class NeedYieldEvent : public Event
{
protected:
    void execute();
public:
    Player *player;
    CardFilter *filter;
    GameValue<bool> fulfilled;
    NeedYieldEvent(Player *p, CardFilter *f);
    ~NeedYieldEvent();
    bool happen_success();
};

#endif // NEEDYIELDEVENT_H
