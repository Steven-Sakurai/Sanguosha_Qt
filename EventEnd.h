#ifndef EVENTEND_H
#define EVENTEND_H

#include "Lib.h"
#include "PrimitiveEvent.h"

class Event;

class EventEnd : public PrimitiveEvent
{
public:
    Event *event;
    EventEnd(Event *e);
    ~EventEnd();
    void happen();
    void undo();
};

#endif // EVENTBEGIN_H
