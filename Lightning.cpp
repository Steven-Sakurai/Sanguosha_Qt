#include "Lib.h"
#include "Lightning.h"
#include "JudgeEvent.h"
#include "DamageEvent.h"

bool Lightning::delayedLegalityCheck(Player *target, PreUseStruct *d)
{
    return target==d->player;
}

Lightning::Lightning() : DelayedTrick("闪电")
{
}

void Lightning::resolve(TargetStruct *target, UseStruct *d)
{
    CardInfo info=(new JudgeEvent(target->player))->happen_getInfo();
    if(info.suit==1&&info.rank>=2&&info.rank<=9) (new DamageEvent(target->player,NULL,3,Thunder,d))->happen();
    else if(d->data->cards[0]->zone==&game->resArea)
    {
        Player *p=target->player->nextPlayer;
        while(p!=target->player&&!isLegalTarget(p,d->data)) p=p->nextPlayer;
        (new MoveEvent(vector<MoveStruct*>(1,new MoveStruct(d->data->cards[0],&p->judgeArea))))->happen();
    }
}
