#include "Lib.h"
#include "EventBegin.h"

EventBegin::EventBegin(Event *e)
{
    event=e;
}

EventBegin::~EventBegin()
{
    delete event;
}

void EventBegin::happen(){game->stack.push_back(event);}
void EventBegin::undo(){game->stack.pop_back();}

string EventBegin::toString(Player *p)
{
    return event->toString(p);
}
