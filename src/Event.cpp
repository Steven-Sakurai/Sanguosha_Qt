#include "Lib.h"
#include "Event.h"
#include "EventBegin.h"
#include "EventEnd.h"

Event::Event()
{
    curTiming=nTimings;
}
Event::~Event(){}

void Event::happen()
{
    bool tag=!game->stack.empty()&&game->stack.back()->curTiming==nTimings;
    game->doPrimitive(new EventBegin(this));
    try {execute();} catch(DisturbedException &) {}
    game->doPrimitive(new EventEnd(this));
    if(tag&&!game->stack.back()->curTiming)
    {
        game->stack.back()->curTiming=nTimings;
        throw DisturbedException();
    }
}

void Event::onTiming(Timing t,int i)
{
	curTiming=t;
    game->handleTiming(t,this,i);
    curTiming=nTimings;
}

string Event::toString(Player *p)
{
    return "";
}
