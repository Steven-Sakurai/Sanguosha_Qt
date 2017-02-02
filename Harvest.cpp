#include "Lib.h"
#include "Harvest.h"
#include "UseEvent.h"

bool Harvest::legalityCheck(Player *target, PreUseStruct *d)
{
    return true;
}

Harvest::Harvest() : NonEquipCard("五谷丰登",Trick)
{
    maxTargets=game->nPlayer;
}

void Harvest::resolve(TargetStruct *target, UseStruct *d)
{
    HarvestInit *initSkill=dynamic_cast<HarvestInit*>(d->skills[0]);
    if(initSkill&&!initSkill->cards.empty())
    {
        Card* card=target->player->chooseCard("五谷丰登",initSkill->cards);
        int i;
        for(i=0;initSkill->cards[i]!=card;i++);
        initSkill->cards.erase(initSkill->cards.begin()+i);
        (new MoveEvent(vector<MoveStruct*>(1,new MoveStruct(card,&target->player->hand))))->happen();
    }
}

bool Harvest::isMandatoryTarget(Player *target, PreUseStruct *d)
{
    return isLegalTarget(target,d);
}

vector<SkillEffect *> Harvest::getUseSkill(UseStruct *d)
{
    vector<SkillEffect *> res;
    res.push_back(new HarvestInit(d));
    res.push_back(new HarvestCleanup(d));
    return res;
}

HarvestInit::HarvestInit(UseStruct *d) : Trigger(d->data->player)
{
    data=d;timings.push_back(afterMove);timings.push_back(specialUse);isMandatory=true;priority=2;
}

vector<void *> HarvestInit::getTrigger(Event *e, vector<void *> past)
{
    if(past.empty())
    {
        UseEvent *use=dynamic_cast<UseEvent*>(e);
        if(!use) use=dynamic_cast<UseEvent*>(dynamic_cast<MoveEvent*>(e)->reason);
        if(use&&use->data==data) return vector<void*>(1,(void*)NULL);
    }
    return vector<void*>();
}

bool HarvestInit::trigger(Event *e, void *index)
{
    if(player->alive)
    {
        cards=game->getTopCards(data->targets.size());
        vector <MoveStruct*> moveData;
        for(int i=0;i<cards.size();i++) moveData.push_back(new MoveStruct(cards[i],&game->resArea));
        (new MoveEvent(moveData))->happen();
        return true;
    }
}

string HarvestInit::toString(Event *e, void *index)
{
    return "五谷翻牌";
}

HarvestCleanup::HarvestCleanup(UseStruct *d) : Trigger(d->data->player)
{
    data=d;timings.push_back(useCleanup);isMandatory=true;priority=2;
}

vector<void *> HarvestCleanup::getTrigger(Event *e, vector<void *> past)
{
    if(past.empty())
    {
        UseEvent *use=dynamic_cast<UseEvent*>(e);
        if(use&&use->data==data) return vector<void*>(1,(void*)NULL);
    }
    return vector<void*>();
}

bool HarvestCleanup::trigger(Event *e, void *index)
{
    HarvestInit *initSkill=dynamic_cast<HarvestInit*>(data->skills[0]);
    if(initSkill&&!initSkill->cards.empty())
    {
        vector <MoveStruct*> moveData;
        for(int i=0;i<initSkill->cards.size();i++)
            moveData.push_back(new MoveStruct(initSkill->cards[i],&game->discardPile));
        (new MoveEvent(moveData))->happen();
    }
    return true;
}

string HarvestCleanup::toString(Event *e, void *index)
{
    return "五谷清理";
}
