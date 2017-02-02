#ifndef COUNTEREVENT_H
#define COUNTEREVENT_H

#include "Lib.h"
#include "ResolveEvent.h"

class CounterEvent : public Event
{
protected:
    void execute();
public:
    ResolveEvent *resolve;
    UseStruct *data;
    CounterEvent(ResolveEvent *r, UseStruct *d);
};

#endif // COUNTEREVENT_H
