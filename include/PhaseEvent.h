/*
 * PhaseEvent.h
 * 
 */
#ifndef _PHASEEVENT_H
#define _PHASEEVENT_H

#include "Lib.h"
#include "Player.h"

class PhaseEvent : public Event
{
protected:
    void execute();
public:
	Player *player;
	Phase phase;
	PhaseEvent(Player *p,Phase ph);
	void end();
};

#endif
