#include "Lib.h"
#include "DamageEvent.h"
#include "HpReductionEvent.h"

void DamageEvent::execute()
{
    if(!player->alive||value<=0) return;
    //TODO: skills like 祸首
    //TODO: skills like 酒
    onTiming(beforeDamage);
    try
    {
        onTiming(beginDamage);
        onTiming(whenDamage);
        onTiming(whenDamaged);
        (new HpReductionEvent(player,value,this))->happen();
        onTiming(afterDamage);
        onTiming(afterDamaged);
        onTiming(endDamage);
    }
    catch(DisturbedException &) {}
    onTiming(afterEndDamage);
    //TODO: triggering chain
}

DamageEvent::DamageEvent(Player *p, Player *s, int v, Nature nat, UseStruct *r):value(v)
{
    player=p;
    source=s;
    nature=nat;
    if(reason=r) cards=r->data->cards;
}

void DamageEvent::prevent()
{
    curTiming=nullTiming;
}

void DamageEvent::changeValue(int delta)
{
    value+=delta;
    if(value<=0) prevent();
}

string DamageEvent::toString(Player *p)
{
    ostringstream s;
    s<<"damage:";
    if(source) s<<source->toString();
    s<<":"<<player->toString()<<":"<<value<<":"<<nature;
    return s.str();
}
