#ifndef EVENTBEGIN_H
#define EVENTBEGIN_H

#include "Lib.h"
#include "PrimitiveEvent.h"

class Event;

class EventBegin : public PrimitiveEvent
{
public:
    Event *event;
    EventBegin(Event *e);
    ~EventBegin();
    void happen();
    void undo();
    string toString(Player *p);
};

#endif // EVENTBEGIN_H
