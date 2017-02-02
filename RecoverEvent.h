#ifndef RECOVEREVENT_H
#define RECOVEREVENT_H
#include "Lib.h"

class RecoverEvent : public Event
{
protected:
    void execute();
public:
    Player *player;
    int value;
    RecoverEvent(Player *p,int v=1);
};

#endif // RECOVEREVENT_H
