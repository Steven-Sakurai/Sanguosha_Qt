#include "Lib.h"
#include "PreUseStruct.h"
#include "CardType.h"

PreUseStruct::PreUseStruct(Player *p, const vector<Card *> &c, CardInfo i, Timing t, Event *r, Transform *trans):info(i)
{
    player=p;cards=c;timing=t;reason=r;transform=trans;testMove=NULL;
}

PreUseStruct::PreUseStruct(Player *p, Card *c, Timing t, Event *r):info(c->getCardInfo())
{
    player=p;cards.push_back(c);timing=t;reason=r;transform=NULL;testMove=NULL;
}

PreUseStruct::PreUseStruct(Player *p, CardType *ct):info(ct,0,0)
{
    player=p;timing=nullTiming;reason=NULL;transform=NULL;testMove=NULL;
}

PreUseStruct::~PreUseStruct()
{
    if(testMove) delete testMove;
}

bool PreUseStruct::use()
{
    return info.name->use(this);
}

bool PreUseStruct::isLegal()
{
    return player->canUseAs(cards,info,timing,reason);
}

int PreUseStruct::getMaxTargets()
{
    int res=info.name->maxTargets;
    game->applyStatics(maxTargetValue,&res,this);
    return res;
}

string PreUseStruct::toString()
{
    string res=player->toString()+":"+info.toString();
    if(transform)
    {
        res+="<"+transform->toString(NULL)+"<";
        for(int i=0;i<cards.size();i++) res+=cards[i]->getPhysicalCardInfo().toString()+";";
    }
    return res;
}
