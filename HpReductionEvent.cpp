#include "Lib.h"
#include "HpReductionEvent.h"
#include "DyingEvent.h"

void HpReductionEvent::execute()
{
    if(!player->alive||value<=0) return;
    player->hp-=value;
    ostringstream s;
    s<<"hp:"<<player->toString()<<":"<<player->hp<<"/"<<player->maxHp;
    for(int i=0;i<game->nPlayer;i++) game->players[i]->inform(s.str());
    if(player->hp<=0) (new DyingEvent(player,damage))->happen();
    onTiming(afterHpReduction);
}

HpReductionEvent::HpReductionEvent(Player *p, int v, DamageEvent *d)
{
    player=p;value=v;damage=d;
}
