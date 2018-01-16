/*
 * PrimitiveEvent.h
 * 
 */
#ifndef _PRIMITIVEEVENT_H
#define _PRIMITIVEEVENT_H

#include "Lib.h"

class Player;

class PrimitiveEvent
{
public:
	virtual ~PrimitiveEvent();
	virtual void happen()=0;
	virtual void undo()=0;
    virtual string toString(Player *p);
};

#endif
