/*
 * MoveEvent.h
 * 
 */
#ifndef _MOVEEVENT_H
#define _MOVEEVENT_H

#include "Lib.h"

class MoveStruct;

class MoveEvent : public Event
{
protected:
    void execute();
public:
	vector<MoveStruct*> data;
	Event *reason;
    MoveEvent(const vector<MoveStruct*> &d,Event *r=NULL);
};

#endif
