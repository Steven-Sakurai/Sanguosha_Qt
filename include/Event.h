/*
 * Event.h
 * 
 */
#ifndef _EVENT_H
#define _EVENT_H

#include "Lib.h"

class Player;

class Event
{
protected:
    virtual void execute()=0;
public:
	GameValue<Timing> curTiming;
    Event();
	virtual ~Event();
    void happen();
    void onTiming(Timing t, int i =-1);
    virtual string toString(Player *p);
};

#endif
