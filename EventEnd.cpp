#include "Lib.h"
#include "EventEnd.h"

EventEnd::EventEnd(Event *e)
{
    event=e;
}

EventEnd::~EventEnd(){}

void EventEnd::happen(){game->stack.pop_back();}
void EventEnd::undo(){game->stack.push_back(event);}
