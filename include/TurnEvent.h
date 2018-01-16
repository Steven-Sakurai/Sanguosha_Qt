/*
 * TurnEvent.h
 * 
 */
#ifndef _TURNEVENT_H
#define _TURNEVENT_H

#include "Lib.h"
#include "Event.h"
#include "GamePointer.h"
#include "PhaseEvent.h"
#include "Player.h"

class TurnEvent : public Event
{
protected:
    void execute();
public:
	Player *player;
	GameValue<Phase> phase;
	GamePointer<PhaseEvent> curPhase;
	GameValue<bool> skipPhase[6];
	TurnEvent(Player *p);
	void end();
};

#endif
