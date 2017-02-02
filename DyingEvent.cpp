#include "Lib.h"
#include "DyingEvent.h"
#include "DeathEvent.h"

void DyingEvent::execute()
{
    onTiming(beginDying);
    int i=-1;
    while(player->hp<=0)
    {
        try
        {
            onTiming(duringDying,i);//TODO: special response rule
            (new DeathEvent(player,damage))->happen();
            break;
        }
        catch(DisturbedException &e) {i=e.index;}
    }
    onTiming(endDying);
}

DyingEvent::DyingEvent(Player *p, DamageEvent *d)
{
    player=p;damage=d;
}

string DyingEvent::toString(Player *p)
{
    string res="dying:";
    res+=player->toString();
    return res;
}
