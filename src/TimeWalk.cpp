#include "Lib.h"
#include "TimeWalk.h"
#include "PhaseEvent.h"
#include "JudgeEvent.h"

bool TimeWalk::delayedLegalityCheck(Player *target, PreUseStruct *d)
{
    return target!=d->player;
}

TimeWalk::TimeWalk() : DelayedTrick("乐不思蜀")
{
}

void TimeWalk::resolve(TargetStruct *target, UseStruct *d)
{
    if((new JudgeEvent(target->player))->happen_getInfo().suit!=2)
        if(target->player==game->curTurn->player)
            game->curTurn->skipPhase[mainPhase]=true;
}
