#include "Lib.h"
#include "Slash.h"
#include "EventBegin.h"
#include "UseEvent.h"
#include "DamageEvent.h"

bool Slash::legalityCheck(Player *target, PreUseStruct *d)
{
    return target!=d->player;
}

bool Slash::distanceCheck(Player *target, PreUseStruct *d)
{
    return d->player->getDistanceTo(target)<=d->player->getRange();
}

Slash::Slash() : NonEquipCard("杀",Basic)
{
}

Slash::~Slash()
{
}

bool Slash::canBeUsed(Timing t, Event *e, Player *p)
{
    if(!NonEquipCard::canBeUsed(t,e,p)) return false;
    if(PhaseEvent *ph=dynamic_cast<PhaseEvent*>(e))
    {
        bool limit=true;
        game->applyStatics(slashLimitApplied,&limit,p);
        if(limit) for(int i=game->timeline.size()-1;i>=0;i--)
        {
            PrimitiveEvent *p=game->timeline[i];
            if(EventBegin *begin=dynamic_cast<EventBegin*>(p))
            {
                if (begin->event==ph) break;
                else if(UseEvent *u=dynamic_cast<UseEvent*>(begin->event))
                    if(u->success&&u->data->data->reason==ph&&dynamic_cast<Slash*>(u->data->data->info.name)) return false;//TODO: skills like 咆哮, 天义, and 龙吟
            }
        }
    }
    return true;
}

void Slash::resolve(TargetStruct *target, UseStruct *d)
{
    (new DamageEvent(target->player,d->data->player,1,Normal,d))->happen();
}
