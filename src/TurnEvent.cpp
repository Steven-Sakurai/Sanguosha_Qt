#include "Lib.h"
#include "TurnEvent.h"
#include "Game.h"

TurnEvent::TurnEvent(Player *p)
{
	player=p;
    for(int i=0;i<6;i++) skipPhase[i]=false;
}

void TurnEvent::execute()
{
    onTiming(beforeTurn);
    if(curTiming)
    {
        try
        {
            game->curTurn=this;
            onTiming(beginTurn);
            for(int i=0;i<6;i++) if(!skipPhase[i])
            {
                phase=(Phase)i;
                (new PhaseEvent(player,phase))->happen();
                if(i<5) onTiming(betweenPhases);
            }
            onTiming(endTurn);
            game->curTurn=NULL;
        }
        catch(DisturbedException &) {}
    }
    onTiming(afterTurn);
}

void TurnEvent::end()
{
	game->curTurn=NULL;
	curTiming=nullTiming;
	curPhase->end();
}
