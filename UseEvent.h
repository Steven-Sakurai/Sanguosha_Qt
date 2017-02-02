#ifndef USEEVENT_H
#define USEEVENT_H

#include "Lib.h"
#include "UseStruct.h"

class UseEvent : public Event
{
protected:
    void execute();
public:
    UseStruct* data;
    GameValue<bool> success;
    int targetId;
    UseEvent(UseStruct *d);
    ~UseEvent();
    string toString(Player *p);
};

#endif // USEEVENT_H
