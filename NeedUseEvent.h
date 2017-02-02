#ifndef NEEDUSEEVENT_H
#define NEEDUSEEVENT_H

#include "Lib.h"
#include "CardFilter.h"

class NeedUseEvent : public Event
{
protected:
    void execute();
public:
    Player *player;
    CardFilter *filter;
    vector<Player*> target;
    GameValue<bool> fulfilled;
    NeedUseEvent(Player *p, CardFilter *f, vector<Player*> t);
    ~NeedUseEvent();
    bool happen_success();
};

#endif // NEEDUSEEVENT_H
