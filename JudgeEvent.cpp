#include "Lib.h"
#include "JudgeEvent.h"
#include "MoveEvent.h"

void JudgeEvent::execute()
{
    if(!player->alive) return;
    onTiming(doJudge);
    if(!card)
    {
        card=game->getTopCards(1)[0];
        (new MoveEvent(vector<MoveStruct*>(1,new MoveStruct(card,&game->resArea)),this))->happen();
    }
    onTiming(beforeJudgeResult);
    info=card->getCardInfo();
    onTiming(afterJudgeResult);
    if(card->zone==&game->resArea)
    {
        (new MoveEvent(vector<MoveStruct*>(1,new MoveStruct(card,&game->discardPile)),this))->happen();
    }
}

JudgeEvent::JudgeEvent(Player *p) : info(NULL,0,0)
{
    player=p;card=NULL;
}

CardInfo JudgeEvent::JudgeEvent::happen_getInfo()
{
    happen();
    return info;
}
