/*
 * DiscardEvent.h
 * 
 */
#ifndef _DISCARDEVENT_H
#define _DISCARDEVENT_H

#include "Lib.h"

class DiscardEvent : public Event
{
protected:
    void execute();
public:
	Player *player;
	vector<Card*> cards;
    DiscardEvent(Player *p,const vector<Card*> &c);
};

#endif
