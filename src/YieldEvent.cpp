#include "Lib.h"
#include "YieldEvent.h"
#include "MoveEvent.h"
#include "NeedYieldEvent.h"

void YieldEvent::execute()
{
    if(!isLegal()) return;
    vector<MoveStruct*> moveData;
    Zone* targetZone=&game->discardPile;//TODO: special kind of yielding
    int i;
    for(i=0;i<cards.size();i++) moveData.push_back(new MoveStruct(cards[i],targetZone));
    (new MoveEvent(moveData,this))->happen();
    if(cards.empty()||isSpecial) onTiming(specialYield);
    if(NeedYieldEvent *need=dynamic_cast<NeedYieldEvent*>(reason))
    {
        if(need->filter->filter(info))
        {
            need->fulfilled=true;
            need->curTiming=nullTiming;
        }
    }
}

YieldEvent::YieldEvent(Player *p, const vector<Card *> &c, CardInfo i, Event *r, Transform *trans, bool sp):info(i)
{
    player=p;cards=c;reason=r;transform=trans;isSpecial=sp;
}

YieldEvent::YieldEvent(Player *p, Card *c, Event *r):info(c->getCardInfo())
{
    player=p;cards.push_back(c);reason=r;transform=NULL;isSpecial=false;
}

bool YieldEvent::isLegal()
{
    return player->canYieldAs(cards,info,reason);
}

string YieldEvent::toString(Player *p)
{
    string res="yield:"+player->toString()+":"+info.toString();
    if(transform)
    {
        res+="<"+transform->toString(NULL)+"<";
        for(int i=0;i<cards.size();i++) res+=cards[i]->getPhysicalCardInfo().toString()+";";
    }
    return res;
}
