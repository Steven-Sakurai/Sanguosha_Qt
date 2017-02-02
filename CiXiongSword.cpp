#include "Lib.h"
#include "CiXiongSword.h"
#include "UseEvent.h"
#include "TargetStruct.h"
#include "Slash.h"

CiXiongSword::CiXiongSword() : WeaponCard("雌雄双股剑",2)
{
}

vector<SkillEffect *> CiXiongSword::getEquipSkill(Player *p)
{
    return vector<SkillEffect *>(1,new CiXiongSkill(p));
}

CiXiongSkill::CiXiongSkill(Player *p) : Trigger(p)
{
    timings.push_back(afterTarget);priority=1;
}

vector<void*> CiXiongSkill::getTrigger(Event *e, vector<void *> past)
{
    vector<void*> res;
    UseEvent *use=dynamic_cast<UseEvent*>(e);
    if(use->data->data->player==player&&dynamic_cast<Slash*>(use->data->data->info.name))
    {
        int i=0;
        if(!past.empty())
        {
            void *last=past.back();
            while(use->data->targets[i++]!=last);
        }
        for(;i<use->data->targets.size();i++)
            if(use->data->targets[i]->player->isMale()!=player->isMale())
                res.push_back(use->data->targets[i]);
    }
    return res;
}

bool CiXiongSkill::trigger(Event *e, void *index)
{
    Player *target=((TargetStruct*)index)->player;
    vector<Card*> cards;
    for(int i=0;i<game->nPlayer;i++) game->players[i]->inform(player->toString()+"对"+target->toString()+"发动了雌雄双股剑");
    for(Card *c=target->hand.next;c!=&target->hand;c=c->next) if(target->canDiscard(c)) cards.push_back(c);
    Card *res=target->chooseCard("discard:"+player->toString()+"对你发动雌雄双股剑",cards,"令对方摸一张牌");
    if(res) target->discard(vector<Card*>(1,res));
    else player->draw(1);
    return true;
}

string CiXiongSkill::toString(Event *e, void *index)
{
    string res="雌雄双股剑（";
    TargetStruct *target=(TargetStruct*)index;
    res+=target->toString()+"）";
    return res;
}
